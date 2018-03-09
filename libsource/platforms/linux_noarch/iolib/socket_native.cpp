///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/iolib/socket_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Stream buffer
//  Comment(s):
//  Library:      System
//  Created:      2007-01-12
//  Updated:      2007-01-12
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <iolib/socket.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/logger.hpp>
#include <systemlib/time.hpp>
#include <new>
#include <cstdarg>

using namespace EXNGPrivate;
using namespace IO;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  StreamBuffer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DECLARE_MIN_RTTI(IO::SocketConnectError)

#ifdef EXNG2_BUILD_AVOID_BLOAT
extern "C" {
  void throwIOSocketConnectError(void)
  {
    throw IO::SocketConnectError();
  }
}
#endif

void Socket::BufferList::appendNew(Socket::Buffer* buffer)
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("BufferList::appendNew");
//   trace.printf("buffer: %p, head: %p, tail:%p\n", buffer, head, tail);
// #endif

  if (buffer) {
    if (tail) {
      buffer->prev  = tail;
      buffer->next  = 0;
      tail->next    = buffer;
      tail          = buffer;

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("appended Buffer\n");
//       trace.printf("buffer: %p, head: %p, tail:%p\n", buffer, head, tail);
// #endif

    } else {
      // entirely new
      head = tail = buffer;

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("starting new Buffer list, head: %p, tail:%p\n", head, tail);
// #endif

    }
  }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   else {
//     trace.printf("null pointer\n");
//   }
// #endif

}

////////////////////////////////////////////////////////////////////////////////

Socket::Buffer* Socket::BufferList::removeOld()
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("BufferList::removeOld");
//   trace.printf("head: %p, tail:%p\n", head, tail);
//
//   if (head) {
//     trace.printf("head->next: %p, head->prev: %p\n", head->next, head->prev);
//   }
//
//   if (tail) {
//     trace.printf("tail->next: %p, tail->prev: %p\n", tail->next, tail->prev);
//   }
//
// #endif

  Buffer* old = 0;
  if (head) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("removed entry\n");
// #endif

    old       = head;
    head      = old->next;
    old->reset();

    // last entry gone
    if (!head) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("last entry removed\n");
// #endif

      tail = 0;
    }
  }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   else {
//     trace.printf("nothing to remove\n");
//   }
// #endif

  return old;
}

////////////////////////////////////////////////////////////////////////////////

Socket::BufferList::~BufferList()
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::BufferList::<destructor>");
// #endif

  int i=0;
  Socket::Buffer* p;
  while ( (p = removeOld()) ) {
// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("deleting Buffer at %p\n", p);
// #endif
    delete p;
    ++i;
  }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   trace.printf("deleted %d Buffer(s)\n", i);
// #endif

}

////////////////////////////////////////////////////////////////////////////////

Socket::Socket(const char* serverIP, uint32 port, int sockWait, int readWait, uint32 max) :
        allocated(), free(),
        socketTimeout(DEF_SOCK_TIMEOUT), readTimeout(DEF_READ_TIMEOUT),
        socketFD(-1), server(0), outputBuffer(0), outputBufferLen(DEF_WRITE_BUFFER),
        bytesBuffered(0),
        numBuffers(0), maxBuffers(max)
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::<constructor>");
// #endif

  if (serverIP) {
    connect(serverIP, port, sockWait, readWait);
  }
}

void Socket::setSocketReadTimeout(int sockWait)
{
  socketTimeout = sockWait < MIN_SOCK_TIMEOUT ? MIN_SOCK_TIMEOUT :
                  sockWait > MAX_SOCK_TIMEOUT ? MAX_SOCK_TIMEOUT :
                  sockWait;
}

void Socket::setOverallReadTimeout(int readWait)
{
  readTimeout   = readWait < MIN_READ_TIMEOUT ? MIN_READ_TIMEOUT :
                  readWait > MAX_READ_TIMEOUT ? MAX_READ_TIMEOUT :
                  readWait;
}

////////////////////////////////////////////////////////////////////////////////

Socket::~Socket()
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::<destructor>");
// #endif

  disconnect();
  if (outputBuffer) {
    Mem::free(outputBuffer);

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("freed write buffer\n");
// #endif

  }
}

////////////////////////////////////////////////////////////////////////////////

void Socket::connect(const char* serverIP, uint32 port, int sockWait, int readWait)
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::connect");
// #endif

  if (socketFD<0) {
    // socket must already be unallocated

    setSocketReadTimeout(sockWait);
    setOverallReadTimeout(readWait);

    // get socket file descriptor
    socketFD = socket(PF_INET, SOCK_STREAM, 0);
    if (socketFD>=0) {
      if ((server = gethostbyname(serverIP))) {
        Mem::zero(&serverAddress, sizeof(serverAddress));
        serverAddress.sin_family = AF_INET;
        Mem::copy(&serverAddress.sin_addr.s_addr, server->h_addr, server->h_length);
        serverAddress.sin_port = htons(port);
        if (::connect(socketFD, (sockaddr*)&serverAddress, sizeof(serverAddress))>=0) {
          // success!

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//           trace.printf("sucessfully connected to %s:%u\n", serverIP, (unsigned)port);
// #endif

          return;
        } else {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//           trace.printf("failed to connect() to host\n");
// #endif

        }
      }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       else {
//         trace.printf("unable to resolve host %s\n", serverIP);
//       }
// #endif

      // something went wrong after getting the socket, so free it up
      disconnect();
    }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     else {
//       trace.printf("failed to obtain a descriptor\n");
//     }
// #endif

  }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   else {
//     trace.printf("already connected to an existing location\n");
//   }
// #endif

  // pete tong

  //throwSocketConnectError();
  THROW_NSX(IO, SocketConnectError());
}

////////////////////////////////////////////////////////////////////////////////

void Socket::disconnect()
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::disconnect");
// #endif

  if (socketFD>=0) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("closing descriptor\n");
// #endif

    close(socketFD);
    socketFD  = -1;

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("transferring Buffers to recycle list...\n");
// #endif

    // recycle buffers
    int i     = 0;
    Buffer*   p;
    while ( (p = allocated.removeOld()) && i<10) {
// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("Removed buffer at %p from allocation list to free list\n");
// #endif
      free.appendNew(p);
      ++i;
    }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("recycled %d Buffer(s)\n", i);
// #endif

  }
}

////////////////////////////////////////////////////////////////////////////////

Socket::Buffer* Socket::allocateBuffer()
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::allocateBuffer");
//
//   // try to recycle an old buffer before allocating a fresh one
//   trace.printf("attempting to recycle a Buffer\n");
// #endif

  Buffer* p = free.removeOld();
  if (!p) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("no old Buffers to recycle, allocating a fresh one\n");
// #endif

    if (maxBuffers!=0 && numBuffers==maxBuffers) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("Exceeded buffer allocation (%u) limit for this Socket\n", (unsigned)maxBuffers);
// #endif

      //throwOutOfMemory();
      THROW_NSX(Error, ResourceExhausted("Socket Buffers"));
    }

    if (!(p = new (std::nothrow) Buffer())) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("unable to allocate a new Buffer\n");
// #endif

      //throwOutOfMemory();
      THROW_NSX(Mem, Exhausted(sizeof(Buffer)));
    }
// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     else {
//       trace.printf("allocated new Buffer at %p\n", p);
//     }
// #endif
    ++numBuffers;
  }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   else {
//     trace.printf("recycled old Buffer\n");
//   }
// #endif

  allocated.appendNew(p);
  return p;
}

////////////////////////////////////////////////////////////////////////////////

void Socket::releaseBuffer()
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::releaseBuffer");
// #endif

  // get the oldest buffer from the used list and shove it in
  // the free list
  Buffer* p = allocated.removeOld();
  if (p) {
    free.appendNew(p);

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("Buffer at %p moved to recycle list\n");
// #endif

  }
}

////////////////////////////////////////////////////////////////////////////////

Socket::Buffer* Socket::getBufferToFill()
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::getBufferToFill");
// #endif

  Buffer* p = allocated.getTail();
  if (!p) {
    p = allocateBuffer();

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("A: starting new Buffer at %p\n", p);
// #endif

  }
  size_t bufferBytesFree = p->bytesFree();

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   if (bufferBytesFree>0) {
//     trace.printf("got Buffer at %p with %d bytes free\n", p, (int)bufferBytesFree);
//   } else {
//     p = allocateBuffer();
//     trace.printf("B: starting new Buffer at %p\n", p);
//   }
// #else

  if (bufferBytesFree<=0) {
    p = allocateBuffer();
  }

// #endif

  return p;
}

////////////////////////////////////////////////////////////////////////////////

Socket::Buffer* Socket::getBufferToDrain()
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::getBufferToDrain");
// #endif

  Buffer* p = 0;
  while (1) {
    p = allocated.getHead();
    if (!p) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("totally out of data for now\n");
// #endif

      break;
    }
    // if the Buffer is drained, move it to free list and try again
    if (p->bytesAvail()==0) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("head Buffer at %p totally drained, adding to recycle list\n", p);
// #endif

      allocated.removeOld();
      free.appendNew(p);
      continue;
    }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     else {
//       trace.printf("Buffer at %p has %d bytes to drain\n", p, (int)p->bytesAvail());
//     }
// #endif

    break;
  }

  return p;
}


////////////////////////////////////////////////////////////////////////////////

void Socket::rawRead()
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::rawRead");
// #endif

  if (socketFD<0) {
    //throwSocketConnectError();
    THROW_NSX(IO, SocketConnectError());
  }

  Time::MilliClock  timer;
  size_t            bytesRequested;
  ssize_t           bytesReceived;
  timeval           tvTimeout;
  fd_set            readDescriptors;
  uint32            overallTimeout = readTimeout*1000;
  bool              proceed = true;

  tvTimeout.tv_sec    = 0;

  do {
    FD_ZERO(&readDescriptors);
    FD_SET(socketFD, &readDescriptors);

    // get the next buffer that has space in it
    Buffer* buffer    = getBufferToFill();
    bytesRequested    = buffer->bytesFree();
    tvTimeout.tv_usec = socketTimeout*1000;

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("requesting %d bytes from socket with timeout limit of %d ms\n", bytesRequested, socketTimeout);
// #endif

    int selectResult = select(socketFD+1, &readDescriptors, 0, 0, &tvTimeout);
    switch (selectResult) {
      case -1:

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//         trace.printf("got error from select()\n");
// #endif

        //throwSocketConnectError();
        THROW_NSX(IO, SocketConnectError());
        break;
      case 0:

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//         trace.printf("got timeout for select()\n");
// #endif

        proceed = false;
        break;

      default:
        char* &receiveBuffer  = buffer->getWritePointer();
        bytesReceived         = ::read(socketFD, receiveBuffer, bytesRequested);
        if (bytesReceived<0) {
          close(socketFD);
          socketFD = -1;
          //throwSocketConnectError();
          THROW_NSX(IO, SocketConnectError());
        }
        else if (bytesReceived==0) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//           trace.printf("EOF detected in read()\n");
// #endif

          close(socketFD);
          socketFD = -1;
          proceed = false;
        }
        else {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//           trace.printf("received %d bytes from read()\n", bytesReceived);
// #endif

          receiveBuffer   += bytesReceived;
          bytesBuffered   += bytesReceived;
        }
        break;
    }

    if (timer.elapsed()>overallTimeout) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("exceeded maximum read timeout of %d ms\n", overallTimeout);
// #endif

      //throwSocketTimeoutError();
      THROW_NSX(IO, TimeoutError());
    }

  } while (proceed);

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   trace.printf("completed in %d ms\n", (int)timer.elapsed());
// #endif

}

////////////////////////////////////////////////////////////////////////////////

void Socket::printf(const char* text, ...)
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::printf");
// #endif

  if (!text) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("no format string\n");
// #endif

    //throwNullPointer();
    THROW_NSX(Error, NullPointer());
  }
  if (socketFD<0) {
    //throwSocketConnectError();
    THROW_NSX(IO, SocketConnectError());
  }

  if (!outputBuffer) {
    outputBuffer = Mem::alloc<char>(outputBufferLen);
  }

  int outLength = 0;

  while (1) {
    va_list argList;
    va_start(argList, text);
    outLength = vsnprintf(outputBuffer, outputBufferLen, text, argList);
    va_end(argList);
    if (outLength > -1 && ((size_t)outLength < outputBufferLen)) {
      break;
    }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("output text will exceed output buffer length, reallocating\n");
// #endif

    if (outLength > -1) {
      outputBufferLen = outLength+1;  // glibc 2.1
    }
    else {
      outputBufferLen<<=1;               // glibc 2.0
    }
    char* newBuff = Mem::alloc<char>(outputBufferLen);
    Mem::free(outputBuffer);
    outputBuffer = newBuff;
  }

  int bytesWritten = write(socketFD, outputBuffer, outLength);
  if (bytesWritten < outLength) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("failed to write %d bytes to socket\n", outLength);
// #endif
    //throwSocketWriteError();

  }

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   trace.printf("wrote %d bytes to socket\n", bytesWritten);
// #endif

}

////////////////////////////////////////////////////////////////////////////////

size_t Socket::read(char* buffer, size_t len, char stopChar)
{

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   Debug trace("Socket::read");
//
//   if (stopChar>31 && stopChar<127) {
//     trace.printf("Looking for up to %d bytes with stop character='%c'\n", (int)len, stopChar);
//   }
//   else {
//     trace.printf("Looking for up to %d bytes with stop character='0x%02X'\n", (int)len, (unsigned)stopChar);
//   }
// #endif

  size_t  bytesRead = 0;
  char    inChar    = 0;
  Buffer* p         = 0;

  do {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//     trace.printf("Holding %d bytes\n", bytesBuffered);
// #endif

    if (bytesBuffered==0) {
      rawRead();
    }

    if (!(p = getBufferToDrain())) {

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//       trace.printf("out of data\n");
// #endif

      break;
    }

    char* &receiveBuffer  = p->getReadPointer();

    do {
      inChar = *buffer++ = *receiveBuffer++;
      ++bytesRead;
      --bytesBuffered;
    } while (inChar!=stopChar && p->bytesAvail() && bytesRead<len);

  } while (inChar!=stopChar && bytesRead<len);

// #if defined(DEBUG) && (DEBUG>=DEBUG_VERBOSE)
//   trace.printf("read %d bytes\n", (int)bytesRead);
// #endif

  return bytesRead;
}

