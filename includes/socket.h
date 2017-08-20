#ifndef SOCKET_H
#define SOCKET_H
#include "arsenal.h"
class TCP;
class UDP;
#define UDP_ECHO (static unsigned char[]){0x0d, 0x0a, 0x0d, 0x0a}
#define UDP_DNSSTATUS (static unsigned char[]){0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
/*#define UDP_RPCCHECK (unsigned char[]){0x72, 0xFE, 0x1D, 0x13, 0x00, 0x00, 0x00\x00\x00\x00\x00\x02\x00\x01\x86\xA0\x00\x01\x97\x7C\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00}
#define UDP_NTPREQUEST (unsigned char[]){\xE3\x00\x04\xFA\x00\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xC5\x4F\x23\x4B\x71\xB1\x52\xF3}
#define UDP_NETSTAT (unsigned char[]){\x80\xF0\x00\x10\x00\x01\x00\x00\x00\x00\x00\x00\x20CKAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA0000210001}
#define UDP_SNMPV3_GETREQUEST (unsigned char[]){\x30\x3A\x02\x01\x03\x30\x0F\x02\x02\x4A\x69\x02\x03\x00\xFF\xE3\x04\x01\x04\x02\x01\x03\x04\x10\x30\x0E\x04\x00\x02\x01\x00\x02\x01\x00\x04\x00\x04\x00\x04\x00\x30\x12\x04\x00\x04\x00\xA0\x0C\x02\x02\x37\xF0\x02\x01\x00\x02\x01\x00\x30\x00}
#define UDP_MSSQL_CHECK (unsigned char[]){\x02}*/

struct DNS_HEADER
{
    unsigned short id; // identification number
    unsigned char rd :1; // recursion desired
    unsigned char tc :1; // truncated message
    unsigned char aa :1; // authoritive answer
    unsigned char opcode :4; // purpose of message
    unsigned char qr :1; // query/response flag
    unsigned char rcode :4; // response code
    unsigned char cd :1; // checking disabled
    unsigned char ad :1; // authenticated data
    unsigned char z :1; // its z! reserved
    unsigned char ra :1; // recursion available
    unsigned short q_count; // number of question entries
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
};
 

template<class P> class Socket : protected Arsenal {
  protected:
    int sock;
    char datagram[4096];
    struct sockaddr_in server;
    struct sockaddr_in b;
  public:
      void dport(int port){server.sin_port=htons(port);}
      int CONNECT(){return connect(sock , (struct sockaddr *)&server , sizeof(server));};
      template <class Dst> inline void dst(Dst d){server.sin_addr.s_addr=inet_addr(d);}
      template <class Src> void src(Src s){b.sin_addr.s_addr=inet_addr(s);}  
      int LISTEN(int port){b.sin_port=htons(port); return bind(sock, (sockaddr*)&b, sizeof(b));}
      template <class Src> int LISTEN(Src s){b.sin_addr.s_addr=inet_addr(s); return bind(sock, (sockaddr*)&b, sizeof(b));}
      template <class Src> int LISTEN(Src s, int port){b.sin_addr.s_addr=inet_addr(s); b.sin_port=htons(port); return bind(sock, (sockaddr*)&b, sizeof(b));}
      Socket<P>(){b = {};}
};

class UDP : public Socket<UDP> {
public:
  UDP(){server.sin_family=AF_INET;
        this->sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);}
        template <class Msg> int SEND(Msg m, int length){return sendto(this->sock, m, length, MSG_DONTWAIT, (sockaddr*)&this->server, sizeof(this->server));}
        void RECV(void* buf, size_t size){socklen_t fromlen = sizeof(sockaddr);
            ssize_t i = recvfrom(this->sock, buf, size, MSG_DONTWAIT, (sockaddr*)&this->b, &fromlen);
            struct DNS_HEADER* dns; dns = (struct DNS_HEADER*) &buf;}
};

class TCP : public Socket<TCP> {
  public:
  TCP(){this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        this->server.sin_family=AF_INET;}};

#endif
