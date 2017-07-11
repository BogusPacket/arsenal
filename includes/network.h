#ifndef NETWORK_H
#define NETWORK_H
#define ETHERNET_SIZE 14
#define IPV4_RF 0x8000
#define IPV4_DF 0x4000
#define IPV4_MF 0x2000
#define IPV4_OFFMASK 0x1ffff
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
#endif
