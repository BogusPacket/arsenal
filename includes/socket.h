#ifndef SOCKET_H
#define SOCKET_H
#include "arsenal.h"
class TCP;
class UDP;

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
      template <class Src> int LISTEN(Src s){b.sin_addr.s_addr=inet_addr(s); return bind(sock, (sockaddr*)&b, sizeof(b));}
      template <class Src> int LISTEN(Src s, int port){b.sin_addr.s_addr=inet_addr(s); b.sin_port=htons(port); return bind(sock, (sockaddr*)&b, sizeof(b));}
      Socket<P>(){b = {};}
};

class UDP : public Socket<UDP> {
public:
  UDP(){server.sin_family=AF_INET;
        this->sock = socket(AF_INET, SOCK_DGRAM, 0);}
        template <class Msg> int SEND(Msg m, int length){return sendto(this->sock, m, length, 0, (sockaddr*)&this->server, sizeof(this->server));}
        template <class Buf> void RECV((const Buf) buf, int size){int fromlen = sizeof(sockaddr); size_t i = recvfrom(this->sock, buf, size, 0, (sockaddr*)&this->server, &fromlen);}
};

class TCP : public Socket<TCP> {
  public:
  TCP(){this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        this->server.sin_family=AF_INET;}};

#endif
