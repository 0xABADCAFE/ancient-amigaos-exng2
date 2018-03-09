///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/procfsparser.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  CPU control and query
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/error.hpp>
//#include <systemlib/logger.hpp>
#include <platforms/linux_noarch/systemlib/procfsparser.hpp>

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ProcFSParser::ProcFSParser(size_t iniSize) :
  allocSize(iniSize),
  totalData(0),
  totalLines(0),
  buffer(0),
  lines(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ProcFSParser::~ProcFSParser()
{
  if (buffer) {
    std::free(buffer);
  }
  delete[] lines;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ProcFSParser::parse(const char* fileName)
{
  std::FILE* stream;

  if (!fileName) {
    THROW_NSX(Error, NullPointer());
  }
  if ((stream = std::fopen(fileName, "r"))) {
    buffer = loadStreamData(stream);
    std::fclose(stream);
    if (buffer) {
      decomposeToLines();
      return;
    }
  }

  THROW_NSX(Error, ResourceUnavailable(fileName));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* ProcFSParser::loadStreamData(std::FILE* stream)
{
  size_t readLen  = allocSize;
  totalData       = 0;

  char* tBuffer = (char*)std::malloc(allocSize);

  if (tBuffer) {
    size_t  lastRead    = 0;
    char*   bufferPos   = tBuffer;
    do {
      lastRead = std::fread(bufferPos, 1, readLen, stream);
      totalData += lastRead;

      if (totalData == allocSize) {
        allocSize <<= 1;
        char* p;
        if (!(p = (char*)std::realloc(tBuffer, allocSize))) {
          std::free(tBuffer);
          totalData =  0;
          return 0;
        } else {
          tBuffer   = p;
          bufferPos = p + totalData;
        }
      } else {
        bufferPos += lastRead;
      }
    } while (lastRead == readLen);

    // null terminate
    *bufferPos = 0;
  }

  return tBuffer;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ProcFSParser::decomposeToLines()
{
  size_t l   = totalLines;
  totalLines = 0;
  char* p    = buffer;

  while(*p) {
    if (*p++ == '\n') {
      ++totalLines;
    }
  }

  if (totalLines > l || !lines) {
    delete[] lines;
    lines = new char* [totalLines+1];
  }

  l = 0;
  p = buffer+1;
  while (*p) {
    if (*p == '\n') {
      *p = 0;
      lines[l++] = p+1;
    }
    ++p;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char* ProcFSParser::getLine(size_t l)
{
  if (l>totalLines) {
    THROW_NSX(Error, Range());
  }
  return lines[l];
}

