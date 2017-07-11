I=-Iincludes/
CONVERTER=src/converter.cpp


converter modules/converter.cpp:
	g++ modules/converter.cpp $(CONVERTER) $(I) -o arsenal --std=c++11


