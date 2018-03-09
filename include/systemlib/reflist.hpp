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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_UTILITYLIB_REFLIST_HPP_
# define _EXNG2_UTILITYLIB_REFLIST_HPP_

# include <private/systemlib/reflistbase.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RefList<T>
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T> class RefList : private EXNGPrivate::VoidList {

  friend class Iterator;
  friend class RevIterator;
  friend class CheckedIterator;
  friend class CheckedRevIterator;

  friend class ConstIterator;
  friend class RevConstIterator;
  friend class CheckedConstIterator;
  friend class CheckedRevConstIterator;


  public:
    void    clear()         { EXNGPrivate::VoidList::clear(); }
    void    pushFront(T* t) { EXNGPrivate::VoidList::pushFront(t); }
    void    pushBack(T* t)  { EXNGPrivate::VoidList::pushBack(t); }
    T*      popFront()      { return (T*)EXNGPrivate::VoidList::popFront(); }
    T*      popBack()       { return (T*)EXNGPrivate::VoidList::popBack(); }
    sint32  length()        { return EXNGPrivate::VoidList::length(); }
    bool    contains(T* t)  { return EXNGPrivate::VoidList::contains(t); }
    bool    remove(T* t)    { return EXNGPrivate::VoidList::remove(t); }

    RefList() : EXNGPrivate::VoidList() {}

    // iterators

    class   Iterator : private EXNGPrivate::VLFwdItr {
      public:
        T* first()          { return (T*)EXNGPrivate::VLFwdItr::first(); }
        T* next()           { return (T*)EXNGPrivate::VLFwdItr::next(); }

        Iterator(const RefList<T>& r) : EXNGPrivate::VLFwdItr(&r) {}
    };

    class RevIterator : private EXNGPrivate::VLRevItr {
      public:
        T* first()          { return (T*)EXNGPrivate::VLRevItr::first(); }
        T* next()           { return (T*)EXNGPrivate::VLRevItr::next(); }

        RevIterator(const RefList<T>& r) : EXNGPrivate::VLRevItr(&r) {}
    };

    // checked iterators (detect changes make to the list during iteration)

    class CheckedIterator : private EXNGPrivate::VLChkFwdItr {
      public:
        T* first()          { return (T*)EXNGPrivate::VLChkFwdItr::first(); }
        T* next()           { return (T*)EXNGPrivate::VLChkFwdItr::next(); }

        CheckedIterator(const RefList<T>& r) : EXNGPrivate::VLChkFwdItr(&r) {}
    };

    class CheckedRevIterator : private EXNGPrivate::VLChkRevItr {
      public:
        T* first()          { return (T*)EXNGPrivate::VLChkRevItr::first(); }
        T* next()           { return (T*)EXNGPrivate::VLChkRevItr::next(); }

        CheckedRevIterator(const RefList<T>& r) : EXNGPrivate::VLChkRevItr(&r) {}
    };


    // const iterators

    class ConstIterator : private EXNGPrivate::VLFwdItr {
      public:
        const T* first()    { return (T*)EXNGPrivate::VLFwdItr::first(); }
        const T* next()     { return (T*)EXNGPrivate::VLFwdItr::next(); }

        ConstIterator(const RefList<T>& r) : EXNGPrivate::VLFwdItr(&r) {}
    };

    class RevConstIterator : private EXNGPrivate::VLRevItr {
      public:
        const T* first()    { return (T*)EXNGPrivate::VLRevItr::first(); }
        const T* next()     { return (T*)EXNGPrivate::VLRevItr::next(); }

        RevConstIterator(const RefList<T>& r) : EXNGPrivate::VLRevItr(&r) {}
    };

    // checked const iterators (detect changes make to the list during iteration)

    class CheckedConstIterator : private EXNGPrivate::VLChkFwdItr {
      public:
        const T* first()    { return (T*)EXNGPrivate::VLChkFwdItr::first(); }
        const T* next()     { return (T*)EXNGPrivate::VLChkFwdItr::next(); }

        CheckedConstIterator(const RefList<T>& r) : EXNGPrivate::VLChkFwdItr(&r) {}
    };

    class CheckedRevConstIterator : private EXNGPrivate::VLChkRevItr {
      public:
        const T* first()    { return (T*)EXNGPrivate::VLChkRevItr::first(); }
        const T* next()     { return (T*)EXNGPrivate::VLChkRevItr::next(); }

        CheckedRevConstIterator(const RefList<T>& r) : EXNGPrivate::VLChkRevItr(&r) {}
    };
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ConstRefList<T>
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T> class ConstRefList : private EXNGPrivate::VoidList {

  friend class Iterator;
  friend class RevIterator;
  friend class CheckedIterator;
  friend class CheckedRevIterator;

  public:
    void      clear()               { EXNGPrivate::VoidList::clear(); }
    void      pushFront(const T* t) { EXNGPrivate::VoidList::pushFront((T*)t); }
    void      pushBack(const T* t)  { EXNGPrivate::VoidList::pushBack((T*)t); }
    const T*  popFront()            { return (T*)EXNGPrivate::VoidList::popFront(); }
    const T*  popBack()             { return (T*)EXNGPrivate::VoidList::popBack(); }
    sint32    length()              { return EXNGPrivate::VoidList::length(); }
    bool      contains(const T* t)  { return EXNGPrivate::VoidList::contains((T*)t); }
    bool      remove(const T* t)    { return EXNGPrivate::VoidList::remove((T*)t); }

    ConstRefList() : EXNGPrivate::VoidList() {}

    // const iterators

    class Iterator : private EXNGPrivate::VLFwdItr {
      public:
        const T* first()    { return (T*)EXNGPrivate::VLFwdItr::first(); }
        const T* next()     { return (T*)EXNGPrivate::VLFwdItr::next(); }

        Iterator(const ConstRefList<T>& r) : EXNGPrivate::VLFwdItr(&r) {}
    };

    class RevIterator : private EXNGPrivate::VLRevItr {
      public:
        const T* first()    { return (T*)EXNGPrivate::VLRevItr::first(); }
        const T* next()     { return (T*)EXNGPrivate::VLRevItr::next(); }

        RevIterator(const ConstRefList<T>& r) : EXNGPrivate::VLRevItr(&r) {}
    };

    // checked const iterators (detect changes make to the list during iteration)

    class CheckedIterator : private EXNGPrivate::VLChkFwdItr {
      public:
        const T* first()    { return (T*)EXNGPrivate::VLChkFwdItr::first(); }
        const T* next()     { return (T*)EXNGPrivate::VLChkFwdItr::next(); }

        CheckedIterator(const ConstRefList<T>& r) : EXNGPrivate::VLChkFwdItr(&r) {}
    };

    class CheckedRevIterator : private EXNGPrivate::VLChkRevItr {
      public:
        const T* first()    { return (T*)EXNGPrivate::VLChkRevItr::first(); }
        const T* next()     { return (T*)EXNGPrivate::VLChkRevItr::next(); }

        CheckedRevIterator(const ConstRefList<T>& r) : EXNGPrivate::VLChkRevItr(&r) {}
    };
};


#endif
