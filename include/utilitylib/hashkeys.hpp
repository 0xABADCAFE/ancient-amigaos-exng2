///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/haskeys.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Simple string hashing
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

#ifndef _EXNG2_UTILITYLIB_HASHKEY_HPP_
#	define _EXNG2_UTILITYLIB_HASHKEY_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Key32 {
	private:
		uint32 hashVal;
		static uint32 evalHash(const char* text);

	public:
		Key32& operator=(const char* text) {
			hashVal = evalHash(text);
			return *this;
		}

		bool operator==(const Key32& key) const { return hashVal == key.hashVal; }
		bool operator!=(const Key32& key) const { return hashVal != key.hashVal; }

		Key32(const Key32& key) : hashVal(key.hashVal) { }
		Key32(const char* text) { hashVal = evalHash(text); }
		Key32() : hashVal(0) { }
};

class Key64 {
	private:
		uint64 hashVal;
		static uint64 evalHash(const char* text);

	public:
		Key64& operator=(const char* text) {
			hashVal = evalHash(text);
			return *this;
		}

		bool operator==(const Key64& key) const { return hashVal == key.hashVal; }
		bool operator!=(const Key64& key) const { return hashVal != key.hashVal; }

		Key64(const Key64& key) : hashVal(key.hashVal) { }
		Key64(const char* text) { hashVal = evalHash(text); }
		Key64() : hashVal(0) { }
};

#endif
