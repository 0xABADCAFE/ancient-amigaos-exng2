///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/reflistbase.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Base class for RefList template
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/reflist.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/logger.hpp>
#include <private/systemlib/error.hpp>

using namespace EXNGPrivate;

VoidList::Link*	VoidList::linkCache				= 0;
sint32					VoidList::linkCacheSize		= 0;
sint32					VoidList::linkCacheDelta	= VoidList::DEFAULT_DELTA;
sint32					VoidList::linkCacheCount	= 0;
sint32					VoidList::nextFreeLink		= VoidList::NULL_LINK;

LOGGING_DECLARE_CLASSNAME(VoidList)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 VoidList::createLink()
{
	// If the next link will overflow, expand the cache
	if (++linkCacheCount >= linkCacheSize) {
		if (!expandCache()) {
			linkCacheCount--;
			return NULL_LINK;
		}
	}
	sint32 next = nextFreeLink;
	nextFreeLink = linkCache[nextFreeLink].nextFree;
	return next;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VoidList::destroyLink(sint32 link)
{
	if (linkCacheCount > 0 &&
			link != NULL_LINK &&
			link < linkCacheSize &&
			linkCache[link].item !=0
	) {
		linkCache[link].item = 0; // a zero pointer signifies the link is free

		// The newly freed link will become the next available link and the previous
		// existing nextFree will referenced by it
		linkCache[link].nextFree = nextFreeLink;
		nextFreeLink = link;
		// if we are destroying the final link, free the cache
		if (--linkCacheCount == 0) {
			releaseCache();
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool VoidList::expandCache()
{
	LOGGING_DECLARE_FUNCNAME(expandCache)

	// Increase the cache. For now, simply reallocate the data and copy. This works fine as the cache is index based
	// but overall this strategy is pretty lame. A better one would be to allocate blocks in a genuine linked list.

	sint32	newSize		= linkCacheSize + linkCacheDelta;
	Link*		newCache	= (Link*)Mem::alloc(newSize*sizeof(Link));
	if (!newCache) {

		#ifdef EXNG2_BUILD_LOGGED
		SystemLog::write(
			SystemLog::ERROR,
			"%s::%s - failed to allocate %d bytes for link cache\n",
			loggingClassName,
			loggingFuncName,
			newSize*sizeof(Link)
		);
		#endif

		return false;
	}
	if (linkCache) {
		Mem::copy(newCache, linkCache, linkCacheSize*sizeof(Link));
		Mem::free(linkCache);
	}

	linkCache = newCache;

	// initialize the newly added region
	newCache = linkCache + linkCacheSize;
	for (sint32 i = linkCacheSize; i<newSize; i++, newCache++) {
		newCache->nextFree	= i+1;
		newCache->item			= 0;
	}
	nextFreeLink		= linkCacheSize;
	linkCacheSize		= newSize;
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void VoidList::releaseCache()
{
	LOGGING_DECLARE_FUNCNAME(releaseCache)

	if (linkCache) {
		Mem::free(linkCache);
		linkCache			= 0;
		linkCacheSize	= 0;
		nextFreeLink	= NULL_LINK;

		#ifdef EXNG2_BUILD_LOGGED
		SystemLog::write(
			SystemLog::INFO,
			"%s::%s - freed link cache\n",
			loggingClassName,
			loggingFuncName
		);
		#endif

	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VoidList::VoidList() : numLinks(0), revision(0), head(NULL_LINK), tail(NULL_LINK)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VoidList::~VoidList()
{
	sint32 link = head;

	while (link >= 0/*!= NULL_LINK*/) {
		sint32 newLink = linkCache[link].next;
		destroyLink(link);
		link = newLink;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool VoidList::pushFront(void* item)
{
	if (item) {
		sint32 link = createLink();
		if (link >=0 /*!= NULL_LINK*/) {
			Link* l = linkCache + link;

			l->item = item;
			l->prev = NULL_LINK;
			l->next = head;

			if (head < 0/*==NULL_LINK*/) {
				// list was empty, so make the tail also point to this link
				tail = link;
			}
			else {
				// update the old head's previous node to point to this link
				linkCache[head].prev = link;
			}

			// update the list state
			head = link;
			numLinks++;
			revision++;
			return true;
		}
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool VoidList::pushBack(void* item)
{
	if (item) {
		sint32 link = createLink();
		if (link >= 0/*!= NULL_LINK*/) {
			Link* l = linkCache + link;

			l->item = item;
			l->prev = tail;
			l->next = NULL_LINK;

			if (tail < 0 /*==NULL_LINK*/) {
				// list was empty, so make the head also point to this link
				head = link;
			}
			else {
				// update the old tail's next node to point to this link
				linkCache[tail].next = link;
			}

			// update the list state
			tail = link;
			numLinks++;
			revision++;
			return true;
		}
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* VoidList::popFront()
{
	if (head >= 0 /*!= NULL_LINK*/) {
		sint32 gone = head;
		void* item = linkCache[gone].item;

		// update the head to point to whatever was after it
		head = linkCache[gone].next;

		// recycle the link node
		destroyLink(gone);

		if (head < 0/*== NULL_LINK*/) {
			// list is now empty, make sure we update the tail to point to NULL_LINK too
			tail = NULL_LINK;
		}
		else {
			// update new head's prev node to point to NULL_LINK
			linkCache[head].prev = NULL_LINK;
		}

		// update the list state
		numLinks--;
		revision++;
		return item;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* VoidList::popBack()
{
	if (tail >= 0 /*!= NULL_LINK*/) {
		sint32 gone = tail;
		void* item = linkCache[gone].item;

		// update the tail to point to whatever was before it
		tail = linkCache[gone].prev;

		// recycle the link node
		destroyLink(gone);

		if (tail < 0 /*== NULL_LINK*/) {
			// list is now empty, make sure we update the head to point to NULL_LINK too
			head = NULL_LINK;
		}
		else {
			// update new tail's next node to point to NULL_LINK
			linkCache[tail].next = NULL_LINK;
		}

		// update the list state
		numLinks--;
		revision++;
		return item;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 VoidList::find(void* item)
{
	for (sint32 link = head; link >=0; link = linkCache[link].next) {
		if (linkCache[link].item == item) {
			return link;
		}
	}
	return NULL_LINK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool VoidList::remove(void* item)
{
	sint32 link = find(item);
	if (link!=NULL_LINK) {

		sint32 prev = linkCache[link].prev;
		sint32 next = linkCache[link].next;

		// update predecessor
		if (prev != NULL_LINK) {
			linkCache[prev].next = next;
		}

		// update sucessor
		if (next != NULL_LINK) {
			linkCache[next].prev = prev;
		}

		destroyLink(link);
		return true;
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void VoidList::debug()
{
	SystemLog::lock();

	SystemLog::printf(
		SystemLog::INFO,
		"VoidList::debug()\n"
		"Link cache:\n"
		"\t%d nodes allocated, %d nodes used, allocation delta: %d, next free node:%d\n"
		"Current instance:\n"
		"\ttotal links: %d\n"
		"\trevision: %d\n"
		"\thead node:%d\n"
		"\ttail node:%d\n"
		"Node list:\n",
		linkCacheSize,
		linkCacheCount,
		linkCacheDelta,
		nextFreeLink,
		numLinks,
		revision,
		head,
		tail
	);

	for (sint32 link = head; link >= 0; link = linkCache[link].next) {
		SystemLog::printf(
			SystemLog::INFO,
			"\t[%4d:0x%08X %4d:%4d]\n",
			link,
			(unsigned)(linkCache[link].item),
			linkCache[link].prev,
			linkCache[link].next
		);
	}

	SystemLog::printf(SystemLog::INFO, "\n");

	SystemLog::unlock();
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* VLChkFwdItr::next()
{
	if (curr>=0) {
		if (revision != list->revision) {
			throwObjectModified();
		}
		void* item = VoidList::linkCache[curr].item;
		curr = VoidList::linkCache[curr].next;
		return item;
	}
	return 0;
}

void* VLChkFwdItr::first()
{
	revision = list->revision;
	curr = list->head;
	return next();
}


void* VLChkRevItr::next()
{
	if (curr>=0) {
		if (revision != list->revision) {
			throwObjectModified();
		}
		void* item = VoidList::linkCache[curr].item;
		curr = VoidList::linkCache[curr].prev;
		return item;
	}
	return 0;
}

void* VLChkRevItr::first() {
	revision = list->revision;
	curr = list->tail;
	return next();
}
