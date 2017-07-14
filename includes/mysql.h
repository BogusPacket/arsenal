#ifndef MYSQL_H
#define MYSQL_H
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#define SQL_TCP "tcp://"
#define SQL_UDP "udp://"
template<const char* P> class MySQL;

template<>
class MySQL<SQL_TCP> {
  private:
    int port = 3306;
    sql::Driver *driver = NULL;
    sql::Connection *connection = NULL;
  public:
  	template <class H, class U, class P>
	MySQL(H host, U user, P passwd, int port){
		std::string s = MYSQL_PROTO_TCP + host;
		s += ":";
		s += std::to_string(port);
		std::cout << s;	
	}
};
#endif
