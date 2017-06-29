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
	struct bpf_program fp;
        Libpcap(){
		dev = pcap_lookupdev(errbuf);
		lookupnet_flag = pcap_lookupnet(dev, &net, &mask, errbuf);
		return;
	};
	~Libpcap(){
	return;
	}
	void Sniff(pcap_handler callback, const char* filter, int count){
		handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
		pcap_compile(handle, &fp, filter, 0, net);
		pcap_setfilter(handle, &fp);
		pcap_loop(handle, count, (pcap_handler) callback, NULL);
		pcap_freecode(&fp);
		pcap_close(handle);
	}
};

#endif
