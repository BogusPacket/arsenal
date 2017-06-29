#ifndef LIBPCAP_H
#define LIBPCAP_H
#include <pcap.h>
#define SNAP_LEN 65535

class Libpcap {
        public:
        char errbuf[PCAP_ERRBUF_SIZE];
        char* dev;
        bpf_u_int32 net;
        bpf_u_int32 mask;
        pcap_t* handle;
        int lookupnet_flag;
        Libpcap(){
		dev = pcap_lookupdev(errbuf);
		lookupnet_flag = pcap_lookupnet(dev, &net, &mask, errbuf);
		handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
		return;
	};
	~Libpcap(){
	return;
	}
};

#endif
