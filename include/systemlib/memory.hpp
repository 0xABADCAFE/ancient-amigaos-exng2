///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/memory.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Memory allocation / copy / set
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef _EXNG2_SYSTEMLIB_MEMORY_HPP_
# define _EXNG2_SYSTEMLIB_MEMORY_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mem
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <systemlib/memory_native.hpp>

class Mem : private RawMemHandler, private SystemLog {
  public:
    class Exhausted;

    enum {
      NO_THROW  = 0x00000001,
      ZEROFILL  = 0x00000002
    };

    static void*  alloc(size_t size, uint32 flags=0);
    static void   free(void* p);

    static void   quickStringCopy(char* dst, const char* src)       { while (((*dst++) = (*src++))) ;               }
    static void   copy(void* dst, const void* src, size_t len)      { RawMemHandler::copy(dst, src, len);           }
    static void   swap16(void* dst, const void* src, size_t num)    { RawMemHandler::swap16(dst, src, num);         }
    static void   swap32(void* dst, const void* src, size_t num)    { RawMemHandler::swap32(dst, src, num);         }
    static void   swap64(void* dst, const void* src, size_t num)    { RawMemHandler::swap64(dst, src, num);         }
    static void   zero(void* dst, size_t len)                       { RawMemHandler::zero(dst, len);                }
    static void   set(void* dst, int val, size_t len)               { RawMemHandler::set(dst, val, len);            }
    static void   set16(void* dst, uint16 val, size_t num)          { RawMemHandler::set16(dst, val, num);          }
    static void   set32(void* dst, uint32 val, size_t num)          { RawMemHandler::set32(dst, val, num);          }
    static void   set64(void* dst, const uint64& val, size_t num)   { RawMemHandler::set64(dst, val, num);          }

    static size_t getNumAllocations()                               { return numAlloc;                              }
    static size_t getPeakAllocations()                              { return peakAlloc;                             }
    static size_t getTotalSize()                                    { return totSize;                               }
    static size_t getPeakSize()                                     { return peakSize;                              }
    static size_t getTotalRequestedSize()                           { return totRequested;                          }
    static size_t getPeakRequestedSize()                            { return peakRequested;                         }
    static size_t getRemainingFreeSize()                            { return RawMemHandler::getRemainingFreeSize(); }

    static void   debug();

    template<typename T>
    static T*     alloc(size_t num, uint32 flags=0)    { return (T*)alloc(num*sizeof(T), flags); }

  private:
    struct MemInfo;

    static void   init();
    static void   done();

    static MemInfo* head;
    static uint32   memIdentifier;

    static size_t   numAlloc;
    static size_t   peakAlloc;
    static size_t   totSize;
    static size_t   peakSize;
    static size_t   totRequested;
    static size_t   peakRequested;

    friend class  Startup;

    LOGGING_DEFINE_CLASSNAME
};


//# include XP_INCLUDE_PLATFORM("systemlib/memory_native.hpp")

class Mem::Exhausted : public Error::ResourceExhausted {
  DEFINE_MIN_RTTI
  public:
    void    log()   const;
    size_t  size()  const { return allocSize; }

  public:
    Exhausted(size_t);


  private:
    size_t allocSize;
};

#endif
