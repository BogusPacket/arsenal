INC=-Iincludes/
USR_INC=-I/usr/local/include
SRC=src/
CPPCONN =-I/usr/lical/include/cppconn
SQL_ARG=-lmysqlcppconn
TESTS=-Itest/
all:
	g++ -c src/g2a.cpp -o g2a.so $(INC) 
	
mysql_test test/mysql.cpp:
	g++ test/mysql.cpp $(INC) $(USR_INC) $(CPPCONN) $(SQL_ARG) -o mysql_test --std=c++11

autopilot_src src/autopilot.cpp:
	g++ -c src/autopilot.cpp $(INC) -o src/autopilot.o

autopilot_test test/autopilot.cpp:
	g++ test/autopilot.cpp src/autopilot.so -o autopilot $(INC) -L/usr/lib/x86_64-linux-gnu -lcurl

