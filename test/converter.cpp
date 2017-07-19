#include <iostream>
#include "converter.h"

int main(int argc, char* argv[]){
	uint32_t addr = 0x64d2f82a;
	uint32_t switched_addr = IPv4_n2h(addr);
	std::cout << "addr == " << std::bitset<32>(addr) << std::endl;
	std::cout << "switched_addr == " << std::bitset<32>(switched_addr) << std::endl;
	std::string addr_s = IPv4_i2s(addr);
	std::string switched_addr_s = IPv4_i2s(switched_addr);
	std::cout << "IPv4_i2s(addr) " << addr_s << std::endl;
	std::cout << "IPv4_i2s(switched_addr) == " << switched_addr_s << std::endl;
	return 1;
}
