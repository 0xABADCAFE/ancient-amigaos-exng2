///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/iolib/streamio_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Processor query, native implementation
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_IOLIB_STREAM_NATIVE_HPP_
#	define _EXNG2_IOLIB_STREAM_NATIVE_HPP_

#include <private/iolib/streamio.hpp>

namespace OSNative {
	extern "C" {
		#include <proto/dos.h>
	}
};


class AsyncStreamBuffer : public IO {
	protected:
		sint32	bufferSize;
		sint32	fileSize;
		sint32	blockSize;
		uint32	flags;
		uint32	currentBuf;
		uint32	seekOffset;
		sint32	bytesLeft;
		void*		buffers[2];
		void*		offset;

		OSNative::BPTR						file;
		OSNative::MsgPort*				handler;
		OSNative::StandardPacket	packet;
		OSNative::MsgPort					packetPort;


		sint32	waitPacket();
		void		sendPacket(void* p);
		void		requeuePacket();
		void		recordSyncFailure();

		enum {
			WAIT_PACKET = 0x00000001,
			FILE_ATEND	= 0x00000002,
			FILE_START	= 0x00000004,
			FILE_GOOD		= 0x00000008,
			FILE_READ		= 0x00000010,
			FILE_WRITE	= 0x00000020,
			FILE_APPEND	= 0x00000040,
			FILE_TEXT		= 0x00000080,
			FILE_ACCESS	= 0x000000F0,
			BUFF_ERROR	= 0x00010000
		};

		static	bool exists(const char* f);
		bool		create(size_t s);
		void		destroy();

		bool		valid()	const	{ return flags & FILE_GOOD; }
		bool		end() 	const	{ return flags & FILE_ATEND; }
		bool		start()	const	{ return flags & FILE_START; }
		sint32	size() 	const	{ if (!(flags & FILE_ACCESS)) EXNGPrivate::throwIOError(); return fileSize; }

		AsyncStreamBuffer() : file(0), flags(0) { buffers[0] = 0; }
		~AsyncStreamBuffer()	{ destroy(); }

	private:
		LOGGING_DEFINE_CLASSNAME
};

namespace EXNGPrivate {
	class StreamUser;
}

////////////////////////////////////////////////////////////////////////////////
//
//  StreamIn
//
////////////////////////////////////////////////////////////////////////////////

class StreamIn : private AsyncStreamBuffer {
	friend class EXNGPrivate::StreamUser;

	private:
		sint32	getNextCharIO();

	protected:
		sint32	rawWriteBytes(const void* buffer, size_t n, sint32 filePos);

	public:
		void		open(const char* f, bool textMode, size_t s=2048);
		void		close();
		void		flush();
		sint32	tell();
		sint32	seek(sint32 position, IO::SeekMode m=IO::FROM_START);
		bool		valid()			const { return AsyncStreamBuffer::valid(); }
		bool		end() 			const { return AsyncStreamBuffer::end(); }
		bool		start()			const { return AsyncStreamBuffer::start(); }
		sint32	size() 			const { return AsyncStreamBuffer::size(); }
		sint32	getChar()
		{
			if (bytesLeft==0)	{
				return getNextCharIO();
			}
			bytesLeft--;
			return *((char*)offset)++;
		}

		sint32	readBytes(void* buffer, size_t n);

		sint32	read8(void* d, size_t n)	{	return readBytes(d, n);	}
		sint32	read16(void* d, size_t n)	{	return (readBytes(d, n<<1))>>1;	}
		sint32	read32(void* d,size_t n)	{	return (readBytes(d, n<<2))>>2;	}
		sint32	read64(void* d, size_t n)	{	return (readBytes(d, n<<3))>>3;	}

		sint32	read16Swap(void* d, size_t n);
		sint32	read32Swap(void* d, size_t n);
		sint32	read64Swap(void* d, size_t n);
		sint32	readText(char*buf, sint32 max, char mark=0, sint32 num=-1);

	public:
		StreamIn() : AsyncStreamBuffer() {}
		StreamIn(const char* f, bool textMode, size_t s=2048);
		~StreamIn();

	private:
		StreamIn(const StreamIn& ) : AsyncStreamBuffer() {}
		StreamIn& operator=(const StreamIn&) { return *this; }

		LOGGING_DEFINE_CLASSNAME
};

////////////////////////////////////////////////////////////////////////////////
//
//  StreamOut
//
////////////////////////////////////////////////////////////////////////////////

#define STREAMOUT_TEXTBUFFSIZE 2048

class StreamOut : private AsyncStreamBuffer {
	friend class EXNGPrivate::StreamUser;

	private:
		char*		textBuffer;

	protected:
		sint32	rawReadBytes(void* buffer, size_t n, sint32 filePos);

	public:
		void		open(const char* f, bool textMode, bool append = false, size_t s=2048);
		void		close();
		void		flush();
		sint32	tell();
		sint32	seek(sint32 position, IO::SeekMode m=IO::FROM_START);
		bool		valid()			const { return AsyncStreamBuffer::valid(); }
		bool		end() 			const { return AsyncStreamBuffer::end(); }
		bool		start()			const { return AsyncStreamBuffer::start(); }
		sint32	size() 			const { return AsyncStreamBuffer::size(); }
		sint32	putChar(char ch)
		{
			if (bytesLeft==0)	{
				if (waitPacket() < 0)	{
					flags &= ~FILE_GOOD;
					EXNGPrivate::throwStreamWriteError();
				}
				sendPacket(buffers[currentBuf]); // send the current buffer
				currentBuf	^= 1;
				offset			= buffers[currentBuf];
				bytesLeft		= bufferSize;
			}
			bytesLeft--;
			*(((char*)offset)++) = ch;
			return ch;
		}

		sint32	writeBytes(const void* buffer, size_t n);
		sint32	write8(const void* s, size_t n)		{ return writeBytes(s, n); }
		sint32	write16(const void* s, size_t n)	{	return (writeBytes(s, n<<1))>>1; }
		sint32	write32(const void* s, size_t n)	{	return (writeBytes(s, n<<2))>>2; }
		sint32	write64(const void* s, size_t n)	{ return (writeBytes(s, n<<3))>>3; }
		sint32	write16Swap(const void* s, size_t n);
		sint32	write32Swap(const void* s, size_t n);
		sint32	write64Swap(const void* s, size_t n);
		sint32	writeText(const char* format,...);

	public:
		StreamOut() : AsyncStreamBuffer(), textBuffer(0) {}
		StreamOut(const char* f, bool textMode, bool append, size_t s=2048);
		~StreamOut();

	private:
		StreamOut(const StreamOut& ) : AsyncStreamBuffer() {}
		StreamOut& operator=(const StreamOut&) { return *this; }

		LOGGING_DEFINE_CLASSNAME
};

////////////////////////////////////////////////////////////////////////////////
//
//  StreamUser
//
//  Exposes protected StreamIn/Out methods to inheritor
//
////////////////////////////////////////////////////////////////////////////////

namespace EXNGPrivate {

	class StreamUser {
		protected:
			static sint32 rawReadBytes(StreamOut* out, void* buffer, size_t n, sint32 filePos)
			{
				return out->rawReadBytes(buffer, n, filePos);
			}

			static sint32 rawWriteBytes(StreamIn* in, void* buffer, size_t n, sint32 filePos)
			{
				return in->rawWriteBytes(buffer, n, filePos);
			}
	};

};
#endif
