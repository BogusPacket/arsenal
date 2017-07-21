#include "arsenal.h"
#include "socket.h"
#include "g2a.h"
#include "converter.h"

int main(int argc, char* argv[]){
  if (argv[1] == "g2a"){
    G2A a;
    a.updateITEMS(48);
    return 1;
  }
  else if (argv[1] == "converter"){
    uint32_t addr = 0x64d2f82a;
	  uint32_t switched_addr = IPv4_n2h(addr);
	  std::cout << "addr == " << std::bitset<32>(addr) << std::endl;
	  std::cout << "switched_addr == " << std::bitset<32>(switched_addr) << std::endl;
	  std::string addr_s = IPv4_i2s(addr);
	  std::string switched_addr_s = IPv4_i2s(switched_addr);
	  std::cout << "IPv4_i2s(addr) " << addr_s << std::endl;
	  std::cout << "IPv4_i2s(switched_addr) == " << switched_addr_s << std::endl;
	  return 1;
  }  else {std::cout << "argv[1]:\t" << argv[1] << std::endl;
		std::cout << "argv[2]:\t" << argv[2] << std::endl;}
}
