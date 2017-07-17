INC=-Iincludes/
USR_INC=-I/usr/local/include
SRC=src/
CPPCONN =-I/usr/lical/include/cppconn
SQL_ARG=-lmysqlcppconn
TESTS=-Itest/

mysql_test test/mysql.cpp:
	g++ test/mysql.cpp $(INC) $(USR_INC) $(CPPCONN) $(SQL_ARG) -o mysql --std=c++11
autopilot_test development/autopilot.cpp:
	g++ development/autopilot.cpp -o autopilot -L/usr/lib/x86_64-linux-gnu -lcurl

