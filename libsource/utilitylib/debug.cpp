///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/debug.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Simple text hashing
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

#include <xbase.hpp>
#include <utilitylib/debug.hpp>

#include <cstdarg>
#include <cstdio>

int Debug::level = 0;

Debug::Debug(const char* n) : name(n)
{
  std::fprintf(stderr, "%*s", level, "");
  std::fprintf(stderr, "%s() {\n", name ? name : "<unknown>");
  level += 4;
}

Debug::~Debug()
{
  level -= 4;
  std::fprintf(stderr, "%*s}\n", level, "");
}

void Debug::printf(const char* fmt, ...)
{
  std::fprintf(stderr, "%*s", level, "");
  va_list argList;
  va_start(argList, fmt);
  std::vfprintf(stderr, fmt, argList);
  va_end(argList);
}
