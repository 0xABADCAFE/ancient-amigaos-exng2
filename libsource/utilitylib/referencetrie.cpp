///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/referencetrie.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  RefTrie implementation
//  Comment(s):
//  Library:      utility
//  Created:      2010-04-07
//  Updated:      2010-04-07
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <utilitylib/referencetrie.hpp>
#include <systemlib/memory.hpp>

using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LOGGING_DECLARE_CLASSNAME(VoidTrie::NodeBuffer)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VoidTrie::NodeBuffer* VoidTrie::NodeBuffer::create()
{
  LOGGING_DECLARE_FUNCNAME(create);
  VoidTrie::NodeBuffer* p = Mem::alloc<NodeBuffer>(1);
  p->init();

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO, "%s::%s allocated NodeBuffer at %p\n",
    loggingClassName, loggingFuncName, p
  );
  #endif

  return p;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VoidTrie::NodeBuffer::destroy(VoidTrie::NodeBuffer* p)
{
  LOGGING_DECLARE_FUNCNAME(destroy);

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO, "%s::%s releasing NodeBuffer at %p\n",
    loggingClassName, loggingFuncName, p
  );
  #endif

  Mem::free(p);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LOGGING_DECLARE_CLASSNAME(VoidTrie)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VoidTrie::VoidTrie() :
  bufferHead(0), bufferCurrent(0),
  rootNode(0),   totalNodes(0),
  maxKeyLen(0)
{
  //LOGGING_DECLARE_FUNCNAME(constructor)

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VoidTrie::~VoidTrie()
{
  //LOGGING_DECLARE_FUNCNAME(destructor)

  freeNodes();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VoidTrie::freeNodes()
{
  LOGGING_DECLARE_FUNCNAME(freeNodes)

  #ifdef EXNG2_BUILD_LOGGED
  int i=0;
  #endif

  for (NodeBuffer* p = bufferHead; p;) {
    NodeBuffer* next = p->nextBuffer();
    NodeBuffer::destroy(p);
    p = next;

    #ifdef EXNG2_BUILD_LOGGED
    ++i;
    #endif
  }

  rootNode          = 0;
  totalNodes        = 0;
  bufferHead        = 0;
  bufferCurrent     = 0;

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO, "%s::%s released %d NodeBuffer instances\n",
    loggingClassName, loggingFuncName, i
  );
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VoidTrie::Node* VoidTrie::allocNode()
{
  //LOGGING_DECLARE_FUNCNAME(allocNode)
  Node* node = 0;
  if (!(bufferCurrent && (node = bufferCurrent->getNextFree())) ) {
    NodeBuffer* newBuf = NodeBuffer::create();
    node               = newBuf->getNextFree();
    if (!bufferCurrent) {
      bufferHead = bufferCurrent = newBuf;
    }
    else {
      bufferCurrent->append(newBuf);
      bufferCurrent       = newBuf;
    }
  }
  Mem::set32(node, 0, sizeof(Node) / sizeof(uint32));
  ++totalNodes;

//   #ifdef EXNG2_BUILD_LOGGED
//   SystemLog::write(
//     SystemLog::INFO, "%s::%s allocated Node at %p\n",
//     loggingClassName, loggingFuncName, node
//   );
//   #endif

  return node;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VoidTrie::addItem(const char* key, void* item)
{
  LOGGING_DECLARE_FUNCNAME(addItem)

  if (!key || !item) {
    THROW_NSX(Error, NullPointer());
  }

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO, "%s::%s adding item at %p with key '%s'\n",
    loggingClassName, loggingFuncName, item, key
  );
  #endif

  if (!rootNode) {
    rootNode = allocNode();
  }

  Node*         node          = rootNode;
  const uint8*  keyRaw        = (const uint8*)key;
  size_t        keyLen        = 0;
  uint32        nybbleLo;
  uint32        nybbleHi;

  ++node->count;

  while ((nybbleHi = *keyRaw++)) {
    ++keyLen;

    nybbleLo = nybbleHi & 0x0F; nybbleHi >>= 4;

    if (!(node->next[nybbleHi])) {
      node->next[nybbleHi] = allocNode();
    }
    node = node->next[nybbleHi];
    ++node->count;

    if (!(node->next[nybbleLo])) {
      node->next[nybbleLo] = allocNode();
    }
    node = node->next[nybbleLo];
    ++node->count;
  }

  node->item = item;

  if (keyLen>maxKeyLen) {
    maxKeyLen = keyLen;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VoidTrie::addItem(const void* key, size_t keyLen, void* item)
{
  LOGGING_DECLARE_FUNCNAME(addItem)

  if (!key || !item) {
    THROW_NSX(Error, NullPointer());
  }

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO, "%s::%s adding item at %p with key at %p, length %u\n",
    loggingClassName, loggingFuncName, item, key, (unsigned) keyLen
  );
  #endif


  if (!rootNode) {
    rootNode = allocNode();
  }

  Node*         node          = rootNode;
  const uint8*  keyRaw        = (const uint8*)key;
  uint32        nybbleLo;
  uint32        nybbleHi;

  ++node->count;

  if (keyLen>maxKeyLen) {
    maxKeyLen = keyLen;
  }

  while (keyLen--) {
    nybbleHi = *keyRaw++;

    nybbleLo = nybbleHi & 0x0F; nybbleHi >>= 4;

    if (!(node->next[nybbleHi])) {
      node->next[nybbleHi] = allocNode();
    }
    node = node->next[nybbleHi];
    ++node->count;

    if (!(node->next[nybbleLo])) {
      node->next[nybbleLo] = allocNode();
    }
    node = node->next[nybbleLo];
    ++node->count;
  }

  node->item = item;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* VoidTrie::getItem(const char* key)
{
  if (!key || !rootNode) {
    THROW_NSX(Error, NullPointer());
  }
  Node*         node          = rootNode;
  const uint8*  keyRaw        = (const uint8*)key;
  uint32        nybbleLo;
  uint32        nybbleHi;

  while ((nybbleHi = *keyRaw++)) {
    nybbleLo = nybbleHi & 0x0F; nybbleHi >>= 4;
    if (
      !(node = node->next[nybbleHi]) ||
      !(node = node->next[nybbleLo])
    ) {
      return 0;
    }
  }
  return node->item;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* VoidTrie::getItem(const void* key, size_t keyLen)
{
  if (!key || !rootNode) {
    THROW_NSX(Error, NullPointer());
  }
  Node*         node          = rootNode;
  const uint8*  keyRaw        = (const uint8*)key;
  uint32        nybbleLo;
  uint32        nybbleHi;

  while (keyLen--) {
    nybbleHi = *keyRaw++;
    nybbleLo = nybbleHi & 0x0F; nybbleHi >>= 4;
    if (
      !(node = node->next[nybbleHi]) ||
      !(node = node->next[nybbleLo])
    ) {
      return 0;
    }
  }
  return node->item;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VTItr::VTItr(const VoidTrie* t) : trie(t), traversalStack(0), currentDepth(0)
{
  maxDepth = t->getMaxKeyLen();
  traversalStack = Mem::alloc<const VoidTrie::Node*>(maxDepth);
}

VTItr::~VTItr()
{
  if (traversalStack) {
    Mem::free(traversalStack);
  }
}

void VTItr::init()
{
  currentDepth=0;
  traversalStack[0] = trie->rootNode;
}
