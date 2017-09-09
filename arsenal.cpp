#include "arsenal.h"
#include "socket.h"
#include "g2a.h"
using namespace std;
int main(int argc, char* argv[]) {
  if (strcmp(argv[1], "g2a") == 0){
    G2A a;
    a.updateITEMS(48);
  }
  else if (strcmp(argv[1], "dns") == 0){char buf[20]; DNSLookup((unsigned char*) argv[2], &buf[0]);}
	else if (strcmp(argv[1], "req") == 0){
		TCP sock;
		sock.dst("192.30.253.113");
  	sock.dport(80);
		sock.CONNECT();}
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

