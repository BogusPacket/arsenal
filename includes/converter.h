#ifndef CONVERTER_H
#define CONVERTER_H
#include <bitset>
#include <cstdlib>
#include <cstring>

unsigned int IPv4_n2h(unsigned int);
template<typename I, typename S> S int2str(I i)
template <unsigned int, typename S> S int2str(unsigned int i){S s; itoa(i, s, 0); return s;}
template <>
#endif
