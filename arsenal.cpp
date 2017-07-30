#include "arsenal.h"
#include "socket.h"
#include "g2a.h"
#define DNS_QUERY "\x00\x00\x01\x00\x00\x01\x00\x00\x00\x00\x00\x00\x03www\rthepacketgeek\x03com\x00\x00\x01\x00\x01"


int main(int argc, char* argv[]) {
  if (strcmp(argv[1], "g2a") == 0){
    G2A a;
    a.updateITEMS(48);
  }
  
else if (strcmp(argv[1], "socket") == 0){
	UDP sock;
	sock.dst("8.8.8.8");
	sock.dport(53);
	sock.LISTEN((const char*)"127.0.0.1");
	sock.SEND(DNS_QUERY, sizeof(DNS_QUERY));
	char buf[39];
	sock.RECV(buf.c_str(), 39);
	
	
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

