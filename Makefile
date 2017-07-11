I=-Iincludes/
CONVERTER=src/converter.cpp


arsenal:
	g++ arsenal.cpp $(CONVERTER) $(I) -o arsenal


