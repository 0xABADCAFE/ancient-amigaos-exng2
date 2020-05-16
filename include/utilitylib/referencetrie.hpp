///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/reftrie.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Simple reference trie
//  Comment(s):
//  Library:      Utility
//  Created:      2010-07-08
//  Updated:      2010-07-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_UTILITYLIB_REFTRIE_HPP_
# define _EXNG2_UTILITYLIB_REFTRIE_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RefTrie
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// to do - move this out when done
namespace EXNGPrivate {

class VoidTrie {

  friend class VTItr;

  private:
    struct Node {
      Node*   next[16];
      void*   item;
      size_t  count;
    };

    struct NodeBuffer {
      enum {
        // Maxmimum number of nodes per NodeBuffer.
        // 455 is a "magic" value here, gives NodeBuffer sizes of 32768/65536 on 32/64-bit systems
        MAX_NODES = 455,
      };
      NodeBuffer* next;
      size_t      nextFree;
      Node        nodes[MAX_NODES];

      Node*  getNextFree()
      {
        if (nextFree<MAX_NODES) {
          return &nodes[nextFree++];
        }
        return 0;
      }
      void        init()                    { nextFree = 0; next=0; }
      void        append(NodeBuffer* p)     { next = p; }
      NodeBuffer* nextBuffer() const        { return next; }

      static NodeBuffer* create();
      static void        destroy(NodeBuffer* p);

      LOGGING_DEFINE_CLASSNAME
    };

  private:
    NodeBuffer* bufferHead;
    NodeBuffer* bufferCurrent;
    Node*       rootNode;
    size_t      totalNodes;
    size_t      maxKeyLen;


    void        freeNodes();
    Node*       allocNode();

  protected:
    size_t      getNodeCount() const { return totalNodes; }
    size_t      getMaxKeyLen() const { return maxKeyLen; }

    // item keyed by C string
    void        addItem(const char* key, void* item);
    void*       getItem(const char* key);

    // item keyed by raw binary
    void        addItem(const void* key, size_t keyLen, void* item);
    void*       getItem(const void* key, size_t keyLen);

    VoidTrie();
    ~VoidTrie();

  private:
    LOGGING_DEFINE_CLASSNAME

};

class VTItr {

  private:
    const VoidTrie*         trie;
    const VoidTrie::Node**  traversalStack;
    uint8*                  keyRep;
    size_t                  currentDepth;
    size_t                  maxDepth;

    void  init();

  protected:

  protected:
    VTItr(const VoidTrie* t);
    ~VTItr();
};

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  KeyRefTrie
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename K, typename T>
class KeyRefTrie : private EXNGPrivate::VoidTrie {

  public:
    size_t getNodeCount() const { return VoidTrie::getNodeCount(); }

    // item keyed by object
    void addItem(const K& key, T* item)
    {
      VoidTrie::addItem(&key, sizeof(K), item);
    }

    T*   getItem(const K& key)
    {
      return (T*) VoidTrie::getItem(&key, sizeof(K));
    }

    KeyRefTrie() : VoidTrie() {}
    ~KeyRefTrie() {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  KeyRefTrie - specialisation for K*
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename K, typename T>
class KeyRefTrie<K*, T> : private EXNGPrivate::VoidTrie {

  public:
    size_t getNodeCount() const { return VoidTrie::getNodeCount(); }

    // item keyed by object
    void addItem(const K* key, T* item)
    {
      VoidTrie::addItem(key, sizeof(K), item);
    }

    T*   getItem(const K* key)
    {
      return (T*) VoidTrie::getItem(key, sizeof(K));
    }


    KeyRefTrie() : VoidTrie() {}
    ~KeyRefTrie() {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  KeyRefTrie - specialisation for null-terminated const char* key
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
class KeyRefTrie<const char*, T> : private EXNGPrivate::VoidTrie {

  public:
    size_t getNodeCount() const { return VoidTrie::getNodeCount(); }
    size_t getMaxKeyLen() const { return VoidTrie::getMaxKeyLen(); }

    // item keyed by C string
    void addItem(const char* key, T* item)
    {
      VoidTrie::addItem(key, item);
    }

    T*   getItem(const char* key)
    {
      return (T*)VoidTrie::getItem(key);
    }

    KeyRefTrie() : VoidTrie() {}
    ~KeyRefTrie() {}
};



#endif
