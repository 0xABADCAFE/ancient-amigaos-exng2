///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/procfsparser.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Utility for parsing data under the proc filesystem (/proc/)
//  Comment(s):
//  Library:      System
//  Created:      2009-02-05
//  Updated:      2009-02-05
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef _EXNG2_SYSTEMLIB_PROC_FS_PARSER_HPP_
# define _EXNG2_SYSTEMLIB_PROC_FS_PARSER_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  CPU
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cstdio>

namespace EXNGPrivate {

  class ProcFSParser {
    public:

      ProcFSParser(size_t iniSize = 4096);
      ~ProcFSParser();

      void    parse(const char* file);

      size_t  getTotalDataLength()  const { return totalData; }
      size_t  getTotalLineCount()   const { return totalLines; }
      char*   getLine(size_t n);

    private:
      char*   loadStreamData(std::FILE* stream);

      void    decomposeToLines();

      size_t  allocSize;
      size_t  totalData;
      size_t  totalLines;
      char*   buffer;
      char**  lines;
  };


};

#endif
