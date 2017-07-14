#ifndef MYSQL_H
#define MYSQL_H
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#define TCP 1
#define UDP 2
template<const char P> class MySQL;

template<>
class MySQL<TCP> {
  private:
    int port = 3306;
    sql::Driver *driver = NULL;
    sql::Connection *con = NULL;
    	_MySQL()
  public:
  	template <class H, class U, class P>
	MySQL(H host, U user, P passwd){
		std::string s = "tcp://" ;
		s += host;
		s += ":";
		s += std::to_string(port);
		std::cout << s;
		driver = get_driver_instance();
		con = driver->connect(host, user, passwd);
	}
	int setPort(int p){
		if (p < 65535 && p > 0){port = p; return 1;}
		else {return 0;}
	}
	template<class D>void switchDatabase(D d){con->setSchema(d);}
	template<>void switchDatabase(std::string d){con->setSchema(d.c_str());}
	template<class S>
	S execute(S s){
		sql::Statement *stmt;
		sql::ResultSet *res;
		stmt = con->createStatement();
		stmt->execute(s);
		while (res->next()){
			std::cout << "id = " << res->getInt(1); // getInt(1) returns the first column
  			// ... or column names for accessing results.
  			// The latter is recommended.
  			std::cout << ", label = '" << res->getString("label") << "'" << std::endl;
		};
	}
	
	
};
#endif
