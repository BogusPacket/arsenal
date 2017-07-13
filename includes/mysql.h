#ifndef MYSQL_H
#define MYSQL_H
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#define MYSQL_PROTO_TCP "tcp://"
#define MYSQL_PROTO_UDP "udp://"
#define 
template<typename H, typename U, typename P>
class MySQL {
  private:
    sql::Driver *driver = NULL;
    sql::Connection *connection = NULL;
  public:
	MySQL(H host, U user, P passwd, int port, const char proto){
		string s = MYSQL_PROTO_TCP + host;
		s += ":";
		s += std::to_string(port);
		std::cout << s;
	}
};
#endif
