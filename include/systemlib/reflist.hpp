///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/reflist.hpp
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

#ifndef _EXNG2_UTILITYLIB_REFLIST_HPP_
#	define _EXNG2_UTILITYLIB_REFLIST_HPP_

#	include <private/systemlib/reflistbase.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RefList<T>, RefListFwdIterator<T>, RefListRevIterator<T>
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T> class RefList;

template<class T> class RefListFwdIterator : private EXNGPrivate::VLFwdItr {

	public:
		T* first()	{ return (T*)EXNGPrivate::VLFwdItr::first(); }
		T* next()		{ return (T*)EXNGPrivate::VLFwdItr::next(); }

		RefListFwdIterator(const RefList<T>& r) : EXNGPrivate::VLFwdItr(&r) {}
};

template<class T> class RefListRevIterator : private EXNGPrivate::VLRevItr {

	public:
		T* first()	{ return (T*)EXNGPrivate::VLRevItr::first(); }
		T* next()		{ return (T*)EXNGPrivate::VLRevItr::next(); }

		RefListRevIterator(const RefList<T>& r) : EXNGPrivate::VLRevItr(&r) {}
};

template<class T> class RefList : private EXNGPrivate::VoidList {

	friend class RefListFwdIterator<T>;
	friend class RefListRevIterator<T>;

	public:
		bool		pushFront(T* t)	{ return EXNGPrivate::VoidList::pushFront(t); }
		bool		pushBack(T* t)	{ return EXNGPrivate::VoidList::pushBack(t); }
		T*			popFront()			{ return (T*)EXNGPrivate::VoidList::popFront(); }
		T*			popBack()				{ return (T*)EXNGPrivate::VoidList::popBack(); }
		sint32	length()				{ return EXNGPrivate::VoidList::length(); }
		bool		contains(T* t)	{ return EXNGPrivate::VoidList::contains(t); }
		bool		remove(T* t)		{ return EXNGPrivate::VoidList::remove(t); }

		RefList() : EXNGPrivate::VoidList() {}
};

#endif
