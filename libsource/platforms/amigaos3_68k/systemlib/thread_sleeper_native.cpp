///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/thread_sleeper_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Native thread classes
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

#include <systemlib/thread.hpp>
#include <systemlib/logger.hpp>
#include <cstdio>

namespace OSNative {
  extern "C" {
    #include <clib/alib_protos.h>
  }
};


using namespace OSNative;
using namespace Time;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Thread::Sleeper
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LOGGING_DECLARE_CLASSNAME(Thread::Sleeper)

Thread::Sleeper::Sleeper() : timerPort(0), timerIO(0), timerSignal(0), req(0), flags(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Thread::Sleeper::init()
{
  LOGGING_DECLARE_FUNCNAME(init)

  if ( !(timerPort = CreateMsgPort()) ) {
    flags |= PORT_FAIL;

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s - failed to create MsgPort\n",
      loggingClassName, loggingFuncName
    );
    #endif

    return false;
  }
  timerSignal = 1<<timerPort->mp_SigBit;
  if ( !(timerIO = CreateExtIO(timerPort, sizeof(timerequest))) ) {
    flags |= IORQ_FAIL;

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s - failed to create IORequest\n",
      loggingClassName, loggingFuncName
    );
    #endif

    return false;
  }
  if (OpenDevice(TIMERNAME, UNIT_MICROHZ, timerIO, 0)!=0) {
    flags |= OPDV_FAIL;

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s - failed to open %s\n",
      loggingClassName, loggingFuncName, TIMERNAME
    );
    #endif

    return false;
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::Sleeper::done()
{
  //LOGGING_DECLARE_FUNCNAME(done)

  if (timerIO) {
    if (flags & IORQ_USED) {
      AbortIO(timerIO);
      WaitIO(timerIO);
      SetSignal(0, timerSignal);
    }
    CloseDevice(timerIO);
    DeleteExtIO(timerIO);
  }
  if (timerPort) {
    DeleteMsgPort(timerPort);
  }

  timerPort = 0;
  timerIO = 0;
  timerSignal = 0;
  flags = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::Sleeper::abortDelay()
{
  //LOGGING_DECLARE_FUNCNAME(abortDelay)

  // Cancels a scheduled wake up
  if (timerIO && (flags & IORQ_USED)) {
    AbortIO(timerIO);
    WaitIO(timerIO);
    SetSignal(0, timerSignal);
    flags &= ~IORQ_USED;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Thread::Sleeper::suspend(uint32 millis, uint32 trigger)
{
  req = trigger;
  if (!(millis|trigger)) {
    return 0;
  }
  abortDelay();
  if (millis) {
    timerReq->tr_node.io_Command  = TR_ADDREQUEST;
    timerReq->tr_time.tv_secs     = (millis/1000);
    timerReq->tr_time.tv_micro    = 1000*(millis%1000);
    SendIO(timerIO);
    flags |= IORQ_USED;
    flags &= ~IORQ_4EVR;
  }
  else {
    flags |= IORQ_4EVR;
  }
  return Wait(timerSignal|trigger);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Thread::Sleeper::suspend()
{
  if (req) {
    if (timerIO && (flags & IORQ_USED)) {
      if (CheckIO(timerIO)==0) {
        return Wait(req|timerSignal);
      }
      else {
        return timerSignal;
      }
    }
  }
  return 0;
}

