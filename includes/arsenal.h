#ifndef ARSENAL_H
#define ARSENAL_H
#define ETHERNET_SIZE 14
#define IPV4_RF 0x8000
#define IPV4_DF 0x4000
#define IPV4_MF 0x2000
#define IPV4_OFFMASK 0x1ffff
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"
#include <bitset>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
typedef struct Ethernet {
	uint8_t dst[6];
	uint8_t src[6];
	uint16_t type;
} Ethernet;

typedef struct IPv4 {
	uint8_t vhl;
	uint8_t tos;
	uint16_t len;
	uint16_t offset;
	uint8_t ttl;
	uint8_t protocol;
	uint16_t checksum;
	uint32_t src;
	uint32_t dst;
} IPv4;

void libpcap_test();
unsigned int IPv4_n2h(unsigned int);
std::string IPv4_i2s(unsigned int);
#endif
