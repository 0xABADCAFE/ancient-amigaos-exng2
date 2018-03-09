
#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <private/systemlib/error.hpp>
#include <cstdio>

#include "reflist.hpp"

using namespace EXNGPrivate;

VLinkCache::VLinkBlock* VLinkCache::head                = 0;
VLinkCache::VLinkNode*  VLinkCache::nextFreeNode        = 0;
uint32                  VLinkCache::totalNodesUsed      = 0;
uint32                  VLinkCache::totalNodesAllocated = 0;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 VLinkCache::blockUsage(VLinkBlock* block)
{
  // count the number of nodes that are allocated within the block
  uint32 nodesUsed = 0;
  for (sint32 i=0; i<LINK_CACHEUNIT_SIZE; i++) {
    if (block->nodes[i].item != 0) {
      nodesUsed++;
    }
  }
  std::printf("VLinkCache::blockUsage() - %lu nodes in block\n", nodesUsed);
  return nodesUsed;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VLinkCache::destroyCache()
{
  // destroy all allocated blocks
  VLinkBlock* block = head;

  while (block) {
    std::printf("VLinkCache::destroyCache() - freed VLinkBlock at 0x%08X\n", (unsigned)block);
    VLinkBlock* next = block->next;
    Mem::free(block);
    block = next;
  }
  totalNodesAllocated = 0;
  nextFreeNode        = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 VLinkCache::expungeCache()
{
  // destroy only empty blocks - only to be called in memory critical situations
  uint32 blocksRemoved = 0;
  VLinkBlock* block = head;
  while (block) {
    VLinkBlock* next = block->next;
    if (blockUsage(block) == 0) {
      // update the next block's previous node to point to the current block's previous node
      if (next) {
        next->prev = block->prev;
      }
      if (block->prev) {
        // update the previous block final Link to point to the first of the next block, or null if there
        // is no next block
        if (next) {
          block->prev->nodes[LINK_CACHEUNIT_SIZE-1].nextFree = &(next->nodes[0]);
        }
        else {
          block->prev->nodes[LINK_CACHEUNIT_SIZE-1].nextFree = 0;
        }
      }
      // free the block
      Mem::free(block);
      blocksRemoved++;
    }
    block = next;
  }
  return blocksRemoved;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool VLinkCache::expandCache()
{
  VLinkBlock* newBlock = (VLinkBlock*)Mem::alloc(sizeof(VLinkBlock), true);
  if (!newBlock) {
    std::printf("VLinkCache::expandCache() - failed to allocate block\n");
    return false;
  }

  // initialize the newly allocated block. All links have their nextFree pointing to the next link in the current
  // block, except the last link, which has nextFree pointing at null

  newBlock->next = 0;
  newBlock->prev = 0;

  VLinkNode* node = newBlock->nodes;
  sint32 i = LINK_CACHEUNIT_SIZE;
  while (--i) {
    node->nextFree = node+1;
    node->item = 0;
    node++;
  }
  node->nextFree = 0;
  node->item = 0;

  // add the newly created block at the head of the block list
  if (head) {
    std::printf("VLinkCache::expandCache() - inserting block at 0x%08X before list head\n", (unsigned)newBlock);
    head->prev = newBlock;
    newBlock->next = head;
  }
  else {
    std::printf("VLinkCache::expandCache() - setting block at 0x%08X as list head\n", (unsigned)newBlock);
  }
  head = newBlock;

  // If this is the first ever call, nextFreeNode is null. Otherwise, we are dealing with
  // an expansion on allocation of the last remaining link. In the former case, nextFreeNode
  // is set to the newly allocated nodes. In the latter case, the nextFree field of the nextFreeNode
  // is set to the newly allocated nodes.

  if (!nextFreeNode) {
    std::printf("VLinkCache::expandCache() - pointing nextFreeLink at block.nodes[0]\n");
    nextFreeNode = &(newBlock->nodes[0]);
  } else {
    std::printf("VLinkCache::expandCache() - pointing nextFreeLink->nextFree at block.nodes[0]\n");
    if (nextFreeNode->nextFree !=0) {
      throwNullPointer();
    }
    nextFreeNode->nextFree = &(newBlock->nodes[0]);
  }

  totalNodesAllocated += LINK_CACHEUNIT_SIZE;

  for(i=0; i<LINK_CACHEUNIT_SIZE; i++) {
    std::printf("%d:0x%08X, ", i, newBlock->nodes[i].nextFree);
  }
  std::putchar('\n');
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VLinkCache::VLinkNode* VLinkCache::createLink()
{
  std::printf("VLinkCache::createLink() - on entry nextFreeNode: 0x%08X\n", unsigned(nextFreeNode));
  // we need to expand the cache when we have one or less nodes presently free
  if (((totalNodesAllocated - totalNodesUsed)<3) && expandCache()==false) {
    std::printf("VLinkCache::createLink() - failed to allocate space\n");
    return 0;
  }
  totalNodesUsed++;
  std::printf(
    "VLinkCache::createLink() - obtained node at 0x%08X, next free: 0x%08X. Total:%lu, used:%lu\n",
    (unsigned)nextFreeNode,
    (unsigned)nextFreeNode->nextFree,
    totalNodesAllocated,
    totalNodesUsed
  );

  VLinkNode* result = nextFreeNode;
  nextFreeNode = result->nextFree;
  return result;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VLinkCache::destroyLink(VLinkCache::VLinkNode* node)
{
  if (node!=0 && node->item!=0 && totalNodesUsed>0) {
    std::printf(
      "VLinkCache::destroyLink() - returning node at 0x%08X to pool. Total:%lu, used:%lu\n",
      unsigned(node),
      totalNodesAllocated,
      totalNodesUsed
    );

    // newly freed node will become the nextFreeNode and the previous nextFreeNode will become
    // this node's nextFree
    if (--totalNodesUsed == 0) {
      destroyCache();
    }
    else {
      node->item = 0; // zero item signifies node is free
      node->nextFree = nextFreeNode;
      nextFreeNode = node;
    }
  }
}
