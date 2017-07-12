INC=-Iincludes/
USR_INC=-I/usr/local/include
SRC=src/
CPPCONN =-I/usr/lical/include/cppconn
SQL_ARG=-lmysqlcppconn
TESTS=-Itest/


converter modules/converter.cpp:
	g++ converter.cpp $(SRC) $(INC) -o converter --std=c++11

mysql_test test/mysql.cpp:
	g++ test/mysql.cpp $(USR_INC) $(CPPCONN) $(SQL_ARG) -o mysql --std=c++11

