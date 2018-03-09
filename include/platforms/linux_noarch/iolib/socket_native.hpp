///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/iolib/socket_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:
//  Comment(s):
//  Library:      iolib
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_IOLIB_SOCKET_NATIVE_HPP_
# define _EXNG2_IOLIB_SOCKET_NATIVE_HPP_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <unistd.h>

class IO::Socket {
  private:
    #include "socket_native_aux.hpp"

    BufferList  allocated;
    BufferList  free;

    int         socketTimeout;
    int         readTimeout;
    int         socketFD;
    sockaddr_in serverAddress;
    hostent*    server;
    char*       outputBuffer;
    size_t      outputBufferLen;
    size_t      bytesBuffered;
    uint32      numBuffers;
    uint32      maxBuffers;
    // buffer allocation/deallocation. Blocks are recycled automatically
    Buffer*     allocateBuffer();
    void        releaseBuffer();

    Buffer*     getBufferToFill();
    Buffer*     getBufferToDrain();

    void        rawRead();

  public:
    enum {
      MIN_SOCK_TIMEOUT     = 10,
      DEF_SOCK_TIMEOUT     = 100,
      MAX_SOCK_TIMEOUT     = 100000,
      MIN_READ_TIMEOUT     = 0,
      DEF_READ_TIMEOUT     = 10,
      MAX_READ_TIMEOUT     = 60,
      DEF_WRITE_BUFFER     = 8192,
      DEF_ALLOC_BUFFERS    = 1024
    };

    void    setSocketReadTimeout(int t);
    void    setOverallReadTimeout(int t);

    int     getSocketReadTimeout()    const { return socketTimeout; }
    int     getOverallReadTimeout()   const { return readTimeout; }
    uint32  getMaxBuffers()           const { return maxBuffers; }
    uint32  getBuffersAllocated()     const { return numBuffers; }

    void    printf(const char* data, ...);
    size_t  read(char* buffer, size_t len, char stopChar=0);
    void    connect(const char* serverIP, uint32 serverPort, int sockWait, int readWait);
    void    disconnect();

    Socket(const char* serverIP, uint32 serverPort, int sockWait=DEF_SOCK_TIMEOUT, int readWait = DEF_READ_TIMEOUT, uint32 maxAllocated=DEF_ALLOC_BUFFERS );
    ~Socket();
};


#endif
