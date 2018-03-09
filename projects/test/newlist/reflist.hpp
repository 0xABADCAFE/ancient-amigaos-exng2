
#ifndef _NEWLIST_HPP_
#define _NEWLIST_HPP_

namespace EXNGPrivate {

class VLinkCache {
  //protected:
  public:
    enum {
      LINK_CACHEUNIT_SIZE = 8
    };

    // basic node definition
    struct VLinkNode {
      VLinkNode*  prev;
      VLinkNode*  next;
      VLinkNode*  nextFree;
      void*       item;     // payload, null implies node is unused
    };

  public:
    static VLinkNode*   createLink();
    static void         destroyLink(VLinkNode* v);
    static uint32       expungeCache();


  private:
    struct VLinkBlock {
      // simple chained block of LINK_CACHE_UNIT VLinkNode is used to implement
      // a dynamically sizeable cache of VLinkNode instances
      VLinkBlock* prev;
      VLinkBlock* next;
      VLinkNode   nodes[LINK_CACHEUNIT_SIZE];
    };

    static VLinkBlock*  head;
    static VLinkNode*   nextFreeNode;
    static uint32       totalNodesUsed;
    static uint32       totalNodesAllocated;
    // internal cache management routines
    static void         destroyCache();
    static bool         expandCache();
    static uint32       blockUsage(VLinkBlock* block);
};


};

#endif
