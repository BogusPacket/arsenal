#include "arsenal.h"
#include "socket.h"
#include "g2a.h"
using namespace std;

int main(int argc, char* argv[]) {
  if (strcmp(argv[1], "g2a") == 0){
    G2A a;
    a.updateITEMS(48);
  }
  
else if (strcmp(argv[1], "dns") == 0){
	UDP sock;
	sock.dst("8.8.8.8");
	sock.dport(53);
	sock.src("104.36.18.123");
	sock.LISTEN("104.36.18.123", 53);
	//sock.SEND(UDP_DNSSTATUS, sizeof(UDP_DNSSTATUS));
	//struct DNS_HEADER* dns = (struct DNS_HEADER*) &buf;
	
	char buf[sizeof(DNS_HEADER) + sizeof(DNS_QUESTION) + strlen(argv[2])];
	DNS_HEADER *dns = &buf;
	dns->id = (unsigned short) htons(1);
	dns->q_count = htons(1);
	memcpy(&buf[sizeof(DNS_HEADER)], argv[2], strlen(argv[2]));
	struct DNS_QUESTION* qu = &buf[sizeof(DNS_HEADER)] + strlen(argv[2])];
	qu->qclass = htons(1);
	qu->qtype = htons(1);
}
return 1;}
/*else if (strcmp(argv[1], "converter") == 0){
    uint32_t addr = 0x64d2f82a;
uint32_t switched_addr = IPv4_n2h(addr);
	  std::cout << "addr == " << std::bitset<32>(addr) << std::endl;
	  std::cout << "switched_addr == " << std::bitset<32>(switched_addr) << std::endl;
	  std::string addr_s = IPv4_i2s(addr);
	  std::string switched_addr_s = IPv4_i2s(switched_addr);
	  std::cout << "IPv4_i2s(addr) " << addr_s << std::endl;
	  std::cout << "IPv4_i2s(switched_addr) == " << switched_addr_s << std::endl;
	  }*/

