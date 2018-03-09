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

#ifndef _EXNG2_IOLIB_SOCKET_NATIVE_AUX_HPP_
# define _EXNG2_IOLIB_SOCKET_NATIVE_AUX_HPP_

class BufferList;
class Buffer {
  // Linkable blocks of storage
  friend class Socket::BufferList;
  public:
    enum {
      PAGE_SIZE = 4096,
      INFO_SIZE = 2*(sizeof(Buffer*)+sizeof(char*)),
      DATA_SIZE = PAGE_SIZE - INFO_SIZE
    };

  private:
    Buffer* prev;
    Buffer* next;
    char*   inBufferPos;
    char*   readBufferPos;
    char    data[ PAGE_SIZE - 2*(sizeof(Buffer*)+sizeof(char*)) ];

  public:

    size_t  bytesFree()         { return (DATA_SIZE - (size_t)(inBufferPos-data)); }
    size_t  bytesAvail()        { return (size_t) (inBufferPos-readBufferPos); }
    char*   &getWritePointer()  { return inBufferPos; }
    char*   &getReadPointer()   { return readBufferPos; }

    void reset()
    {
      prev = next = 0;
      readBufferPos = inBufferPos = data;
    }

    Buffer() : prev(0), next(0)
    {
      readBufferPos = inBufferPos = data;
    }

};

// Implement a list for Buffer blocks that allows newly allocated blocks
// to be added at the tail end and removed from the head end only
class BufferList {
  private:
    Socket::Buffer* head;
    Socket::Buffer* tail;

  public:
    BufferList() : head(0), tail(0) {}
    ~BufferList();

    void              appendNew(Socket::Buffer*);
    Socket::Buffer*   removeOld();
    Socket::Buffer*   getHead()
    {
      return head;
    }
    Socket::Buffer*   getTail()
    {
      return tail;
    }
};


#endif
