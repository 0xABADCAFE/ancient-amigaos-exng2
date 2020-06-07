///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DBTestApp
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <xbase.hpp>
#include <systemlib/logger.hpp>
#include <dblib/db_mysql.hpp>
#include <cstdio>
#include <memory>

class DBTestApp : public Application
{
  public:
    sint32 run();

  public:
    DBTestApp();
    ~DBTestApp();

  private:
    static const char* host;
    static const char* user;
    static const char* pass;
    static const char* dbName;

    DB::Instance* db;
};

const char* DBTestApp::host    = "localhost";
const char* DBTestApp::user    = "exng2dbuser";
const char* DBTestApp::pass    = "yetanotherstupidpassord";
const char* DBTestApp::dbName  = "exng2test";

Application* Application::createInstance()
{
  return new DBTestApp();
}

void Application::destroyInstance(Application* app)
{
  delete app;
}

DBTestApp::DBTestApp() : db(0)
{
  db = MySQL::createInstance();
}

DBTestApp::~DBTestApp()
{
  MySQL::destroyInstance(db);
}

sint32 DBTestApp::run()
{
  std::printf("DB Test\n");

  if (db->open(host, user, pass, dbName, 0, 3306)) {
    std::printf("Server : %s\n", db->getServerInfo());
    db->close();
  }

  return 0;
}
