#include "arsenal.h"
#include "socket.h"

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


