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

        unsigned char name[] = {"3www6google3com"};
        char buf[sizeof(DNS_HEADER) + sizeof(DNS_QUESTION) + sizeof(name)];
        DNS_HEADER *dns = (struct DNS_HEADER*) &buf[0];
        dns->id = (unsigned short) htons(1);
        dns->qr = 0; //This is a query
         dns->opcode = 0; //This is a standard query
        dns->aa = 0; //Not Authoritative
        dns->tc = 0; //This message is not truncated
    dns->rd = 1; //Recursion Desired
    dns->ra = 0; //Recursion not available! hey we dont have it (lol)
    dns->z = 0;
    dns->ad = 0;
    dns->cd = 0;
    dns->rcode = 0;
    dns->q_count = htons(1); //we have only 1 question
    dns->ans_count = 0;
    dns->auth_count = 0;
    dns->add_count = 0;

        memcpy(&buf[sizeof(DNS_HEADER)], &name[0], sizeof(name));
        struct DNS_QUESTION* qu = (struct DNS_QUESTION*) &buf[sizeof(DNS_HEADER) + sizeof(name)];
        qu->qclass = htons(1);
        qu->qtype = htons(1);
        sock.SEND(buf, sizeof(buf));
        char buf1[100];
        sock.RECV(buf1, 100);
        printDNS_HEADER((struct DNS_HEADER*) &buf1[0]);
} return 1;}
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

