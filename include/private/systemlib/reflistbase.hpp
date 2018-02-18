///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         private/utilitylib/reflistbase.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Simple list
//  Comment(s):
//  Library:      utility
//  Created:      2007-04-07
//  Updated:      2007-04-07
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _EXNG2_UTILITYLIB_REFLISTBASE_HPP_
#	define _EXNG2_UTILITYLIB_REFLISTBASE_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  EXNGPrivate::VoidList
//
//  Simple linked list of generic pointers, used as a common code base for
//  the type-safe list based containers. This prevents the usual template
//  bloat since all the real work is done here and the template is just
//  used as a type safe wrapper.
//
//  This class only handles references to objects and does not perform any
//  operations of any kind on the objects referenced.
//
//  Each link is comprised of the usual previous / next info and a void* pointer
//  to the object referenced. Since links need to be allocated every time an
//  object is added to a list, a cacheing system is used for links.
//
//  A single vector of links is maintained, all previous/next references are
//  indecies within the vector. All links allocated from any list instance are
//  allocated from this vector.
//
//  Each link contains a reference to the next free link after itself. Initially
//  this will be the next link in the vector. A static reference to the next
//  free link is maintained within the class itself.
//
//  When a link is freed, the static next free link reference is stored within
//  that links own next free reference. The static next free link then becomes
//  the newly freed link.
//
//  This means that the next unused or most recently freed link will always be
//  the next allocated.
//
//  When the existing link cache reaches capacity, it is expanded by a fixed
//  amount. Since links only reference one another by index, the resizing
//  process can safely copy the existing cache data.
//
//  The entire link system is implemented here and does not propagate beyond
//  this class.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#	include <systemlib/logger.hpp>

namespace EXNGPrivate {

	class VoidList /*: private SystemLog */ {

		friend class VLFwdItr;
		friend class VLRevItr;
		friend class VLChkFwdItr;
		friend class VLChkRevItr;


		private:
			enum {
				NULL_LINK			= -1,
				DEFAULT_DELTA	= 256
			};

			struct Link {
				sint32	prev;
				sint32	next;
				sint32	nextFree;
				void*		item;
			};

			// Link cacheing system
			static Link*	linkCache;
			static sint32	linkCacheSize;		// the current size (in links)
			static sint32	linkCacheDelta;		// the number of links to expand / shrink
			static sint32 linkCacheCount;		// current number of links
			static sint32 nextFreeLink;			// the next freely available link

			static sint32	createLink();
			static void		destroyLink(sint32 l);
			static bool		expandCache();

			static void		releaseCache();

			sint32	head;
			sint32	tail;
			sint32	numLinks;
			sint32	revision;								// updated each time the list is modified

			sint32	find(void* p);

		protected:
			bool		pushFront(void* p);
			bool		pushBack(void* p);
			void*		popFront();
			void*		popBack();
			bool		contains(void *p) 			{ return (find(p)!=NULL_LINK); }
			sint32	length()					const { return numLinks; }
			bool		remove(void* p);
			//void		debug();

			VoidList();

		public:
			static	sint32	setLinkDelta(sint32 d);
			static	sint32	getLinkCacheSize()	{ return linkCacheSize; }
			static	sint32	getLinkCacheDelta()	{ return linkCacheDelta; }
			static	sint32	getLinkCacheUsed()	{ return linkCacheCount; }

			~VoidList();

		private:
			LOGGING_DEFINE_CLASSNAME
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//  Basic iterators (consistency unchecked)
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	class VLFwdItr {
		private:
			const VoidList* list;
			sint32					curr;

		protected:
			void* first();
			void* next();

		protected:
			VLFwdItr(const VoidList* vlist) : list(vlist), curr(VoidList::NULL_LINK) {}
	};

	class VLRevItr {
		private:
			const VoidList* list;
			sint32					curr;

		protected:
			void*	first();
			void*	next();

		protected:
			VLRevItr(const VoidList* vlist) : list(vlist), curr(VoidList::NULL_LINK) {}
	};

	class VLChkFwdItr {
		private:
			const VoidList* list;
			sint32					curr;
			sint32					revision;

		protected:
			void* first();
			void* next();

		protected:
			VLChkFwdItr(const VoidList* vlist) : list(vlist), curr(VoidList::NULL_LINK) {}
	};

	class VLChkRevItr {
		private:
			const VoidList* list;
			sint32					curr;
			sint32					revision;
		protected:
			void*	first();
			void*	next();

		protected:
			VLChkRevItr(const VoidList* vlist) : list(vlist), curr(VoidList::NULL_LINK) {}
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//  Inlines
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	inline void* VLFwdItr::next() {
		if (curr>=0) {
			void* item = VoidList::linkCache[curr].item;
			curr = VoidList::linkCache[curr].next;
			return item;
		}
		return 0;
	}

	inline void* VLFwdItr::first() {
		curr = list->head;
		return next();
	}


	inline void* VLRevItr::next() {
		if (curr>=0) {
			void* item = VoidList::linkCache[curr].item;
			curr = VoidList::linkCache[curr].prev;
			return item;
		}
		return 0;
	}

	inline void* VLRevItr::first() {
		curr = list->tail;
		return next();
	}

};



#endif
