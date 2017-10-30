INC=-Iincludes/
USR_INC=-I/usr/local/include
SRC=src/
CPPCONN =-I/usr/lical/include/cppconn
SQL_ARG=-lmysqlcppconn
TESTS=-Itest/
all:
	g++ -c src/g2a.cpp -o g2a.so $(INC) -L/usr/lib/x86_64-linux-gnu -lcurl --std=c++11
	g++ -c src/socket.cpp -o socket.so $(INC) -L/usr/lib/x86_64-linux-gnu -lcurl --std=c++11
	g++ test.cpp g2a.so socket.so -o test $(INC) -L/usr/lib/x86_64-linux-gnu -lcurl --std=c++11
	
install:
	mv test /usr/bin
