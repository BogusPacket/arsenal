I=-Iincludes/
CONVERTER=src/converter.cpp


arsenal modules/converter.cpp:
	g++ arsenal.cpp $(CONVERTER) $(I) -o arsenal --std=c++11


