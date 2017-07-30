#ifndef SOCKET_H
#define SOCKET_H
#include "arsenal.h"
class TCP;
class UDP;

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
