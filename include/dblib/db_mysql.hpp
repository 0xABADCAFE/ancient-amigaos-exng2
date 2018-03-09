//****************************************************************************//
//**                                                                        **//
//** File:         classes_db_mysql.hpp                                     **//
//** Description:  Factory for mysql implementation of abstract db          **//
//** Comment(s):   Internal developer version only                          **//
//** Library:                                                               **//
//** Author:       Karl Churchill                                           **//
//** Created:      2008-03-29                                               **//
//**                                                                        **//
//****************************************************************************//

#ifndef _EXNG2_DBLIB_MYSQL_HPP_
# define _EXNG2_DBLIB_MYSQL_HPP_

#include "db_abstract.hpp"

class MySQL {
  public:
    static DB::Instance*  createInstance();
    static void           destroyInstance(DB::Instance* db);

    //static Database*  getSharedInstance(DBUsers::UserId);
    //static void       finalizeInstances();

  private:
    //static Database*  shared[DBUsers::MAX_DBUSER];
};


#endif
