#include "converter.h"
#include "arsenal.h"


unsigned int IPv4_n2h(unsigned int arg){
	register unsigned char r4 = *((unsigned char*) &arg);
	register unsigned char r3 = *((unsigned char*) &arg + 1);
	register unsigned char r2 = *((unsigned char*) &arg + 2);
	register unsigned char r1 = *((unsigned char*) &arg + 3);
	register unsigned int r;
	*((unsigned char*) &r) = r1;
	*((unsigned char*) &r + 1) = r2;
	*((unsigned char*) &r + 2) = r3;
	*((unsigned char*)&r + 3) = r4;
	return r;;
}

std::string IPv4_i2s(unsigned int i){
	register unsigned int r1 = *((unsigned char*) &i);
        register unsigned int r2 = *((unsigned char*) &i + 1);
        register unsigned int r3 = *((unsigned char*) &i + 2);
        register unsigned int r4 = *((unsigned char*) &i + 3);
	std::stringstream s;
	s << r1;
	s << ".";
	s << r2;
	s << ".";
	s << r3;
	s << ".";
	s << r4;
	return s.str();
}
