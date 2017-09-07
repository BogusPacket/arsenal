#include "arsenal.h"
#include "socket.h"

template<class Name, class Buf> void DNSLookup(Name n, Buf b){
UDP sock;
sock.dst("8.8.8.8");
sock.dport(53);
sock.src("104.36.18.123");
sock.LISTEN("104.36.18.123", 53);
unsigned char name[] = {"www.google.com"};
unsigned char buf[65535];
DNS_HEADER *dns = (struct DNS_HEADER*) &buf[0];
dns->id = (unsigned short) htons(768);
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
unsigned char* qname = (unsigned char*)&buf[sizeof(struct DNS_HEADER)];
ChangetoDnsNameFormat(qname, name);
struct DNS_QUESTION* qu = (struct DNS_QUESTION*) &buf[sizeof(DNS_HEADER) + (strlen((const char*)qname) + 1)];
qu->qclass = htons(1);
qu->qtype = htons(1);
sock.SEND(buf, sizeof(struct DNS_HEADER) + (strlen((const char*)qname)+1) + sizeof(struct DNS_QUESTION));
unsigned char buf1[100];
sock.RECV(buf1, 100);
printDNS_HEADER((struct DNS_HEADER*) &buf1[0]);}

void printDNS_HEADER(struct DNS_HEADER* h){
  std::cout << COLOR_GREEN << "-----DNS HEADER-----" << std::endl;
  std::cout << "id " << COLOR_RESET << ": " << COLOR_YELLOW << ntohs(h->id) << COLOR_GREEN << std::endl;
  std::cout << "rd " << COLOR_RESET << ": " << COLOR_YELLOW << +h->rd << COLOR_GREEN << std::endl;
  std::cout << "tc " << COLOR_RESET << ": " << COLOR_YELLOW << +h->tc << COLOR_GREEN << std::endl;
  std::cout << "aa " << COLOR_RESET << ": " << COLOR_YELLOW << +h->aa << COLOR_GREEN << std::endl;
  std::cout << "opcode " << COLOR_RESET << ": " << COLOR_YELLOW << +h->opcode << COLOR_GREEN << std::endl;
  std::cout << "qr " << COLOR_RESET << ": " << COLOR_YELLOW << +h->qr << COLOR_GREEN << std::endl;
  std::cout << "rcode " << COLOR_RESET << ": " << COLOR_YELLOW << +h->rcode << COLOR_GREEN << std::endl;
  std::cout << "cd " << COLOR_RESET << ": " << COLOR_YELLOW << +h->cd << COLOR_GREEN << std::endl;
  std::cout << "ad " << COLOR_RESET << ": " << COLOR_YELLOW << +h->ad << COLOR_GREEN << std::endl;
  std::cout << "z " << COLOR_RESET << ": " << COLOR_YELLOW << +h->z << COLOR_GREEN << std::endl;
  std::cout << "ra " << COLOR_RESET << ": " << COLOR_YELLOW << +h->ra << COLOR_GREEN << std::endl;
  std::cout << "q_count " << COLOR_RESET << ": " << COLOR_YELLOW << ntohs(h->q_count) << COLOR_GREEN << std::endl;
  std::cout << "ans_count " << COLOR_RESET << ": " << COLOR_YELLOW << ntohs(h->ans_count) << COLOR_GREEN << std::endl;
  std::cout << "auth_count " << COLOR_RESET << ": " << COLOR_YELLOW << ntohs(h->auth_count) << COLOR_GREEN << std::endl;
  std::cout << "add_count " << COLOR_RESET << ": " << COLOR_YELLOW << ntohs(h->add_count) << COLOR_GREEN << std::endl << COLOR_RESET;
}

unsigned int randIPV4(){
unsigned int ip;
return ip;
}

void ChangetoDnsNameFormat(unsigned char* dns, unsigned char* host) 
{
    int lock = 0 , i;
    strcat((char*)host,".");
     
    for(i = 0 ; i < strlen((char*)host) ; i++) 
    {
        if(host[i]=='.') 
        {
            *dns++ = i-lock;
            for(;lock<i;lock++) 
            {
                *dns++=host[lock];
            }
            lock++; //or lock=i+1;
        }
    }
    *dns++='\0';
}


