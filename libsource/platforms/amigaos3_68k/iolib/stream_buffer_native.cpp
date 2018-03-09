///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/iolib/streamio_native.cpp
//  Tab Size:     2
//  Max Line:
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
#include <systemlib/memory.hpp>
#include <iolib/streamio.hpp>
#include <private/systemlib/error.hpp>

#include <systemlib/logger.hpp>

using namespace OSNative;
using namespace EXNGPrivate;

LOGGING_DECLARE_CLASSNAME(AsyncStreamBuffer)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  AsyncStreamBuffer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AsyncStreamBuffer::sendPacket(void* p)
{
  packet.sp_Pkt.dp_Port = &packetPort;
  packet.sp_Pkt.dp_Arg2 = (sint32)p;
  PutMsg(handler, &packet.sp_Msg);
  flags |= WAIT_PACKET;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 AsyncStreamBuffer::waitPacket()
{
  LOGGING_DECLARE_FUNCNAME(waitPacket)

  if (flags & WAIT_PACKET) {
    while (true) {
      packetPort.mp_Flags = PA_SIGNAL;
      Remove((Node*)WaitPort(&packetPort));

      // Ignore spurious crap
      packetPort.mp_Flags = PA_IGNORE;
      flags &= ~WAIT_PACKET;

      sint32 bytes = packet.sp_Pkt.dp_Res1;
      if (bytes >= 0) {
        return bytes;
      }
      // see if the user wants to try again...
      if (ErrorReport(packet.sp_Pkt.dp_Res2,REPORT_STREAM,file,0)) {
        flags &= ~FILE_GOOD;

        #ifdef EXNG2_BUILD_LOGGED
        SystemLog::write(
          SystemLog::WARNING, "%s::%s - IO failure\n",
          loggingClassName, loggingFuncName
        );
        #endif

        return -1;
      }
      if (flags & FILE_READ) {
        sendPacket(buffers[currentBuf]);
      }
      else {
        sendPacket(buffers[1 - currentBuf]);
      }
    }
  }
  SetIoErr(packet.sp_Pkt.dp_Res2);
  return packet.sp_Pkt.dp_Res1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AsyncStreamBuffer::requeuePacket()
{
  AddHead(&packetPort.mp_MsgList,&packet.sp_Msg.mn_Node);
  flags |= WAIT_PACKET;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AsyncStreamBuffer::recordSyncFailure()
{
  packet.sp_Pkt.dp_Res1 = -1;
  packet.sp_Pkt.dp_Res2 = IoErr();
  bytesLeft = 0;
  flags &= ~FILE_GOOD;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool AsyncStreamBuffer::create(size_t reqSize)
{
  LOGGING_DECLARE_FUNCNAME(create)

  if ((file) && (!buffers[0])) {
    buffers[0] = Mem::alloc(reqSize, Mem::ZEROFILL);
    if (buffers[0]) {
      FileHandle* fh  = (FileHandle*)BADDR(file);
      handler         = fh->fh_Type;
      bufferSize      = reqSize >> 1;
      buffers[1]      = (char*)(buffers[0]) + bufferSize;
      offset          = buffers[0];
      currentBuf      = 0;
      seekOffset      = 0;
      flags &= ~WAIT_PACKET;
      // message port setup
      packetPort.mp_MsgList.lh_Head     = (Node*)&packetPort.mp_MsgList.lh_Tail;
      packetPort.mp_MsgList.lh_Tail     = 0;
      packetPort.mp_MsgList.lh_TailPred = (Node*)&packetPort.mp_MsgList.lh_Head;
      packetPort.mp_Node.ln_Type        = NT_MSGPORT;
      packetPort.mp_Node.ln_Name        = 0;
      packetPort.mp_Flags               = PA_IGNORE;
      packetPort.mp_SigBit              = SIGB_SINGLE;
      packetPort.mp_SigTask             = FindTask(0);
      packet.sp_Pkt.dp_Link             = &packet.sp_Msg;
      packet.sp_Pkt.dp_Arg1             = fh->fh_Arg1;
      packet.sp_Pkt.dp_Arg3             = bufferSize;
      packet.sp_Pkt.dp_Res1             = 0;
      packet.sp_Pkt.dp_Res2             = 0;
      packet.sp_Msg.mn_Node.ln_Name     = (char*)&packet.sp_Pkt;
      packet.sp_Msg.mn_Node.ln_Type     = NT_MESSAGE;
      packet.sp_Msg.mn_Length           = sizeof(StandardPacket);
      return true;
    }
  }

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::ERROR, "%s::%s - Failed to initialise buffer\n",
    loggingClassName, loggingFuncName
  );
  #endif
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AsyncStreamBuffer::destroy()
{
  if (buffers[0]) {
    Mem::free(buffers[0]);
    buffers[0] = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool AsyncStreamBuffer::exists(const char* fileName)
{
  BPTR handle = Open(fileName,MODE_OLDFILE);
  if (handle) {
    Close(handle);
    return true;
  }
  return false;
}


