#include "../includes/arsenal.h"
#include "../includes/libpcap.h"

void got_packet(u_char* args, const struct pcap_pkthdr *header, const u_char *packet){
	struct IPv4* ip = (struct IPv4*)&packet + 14;
	std::cout << IPv4_i2s(IPv4_n2h(ip->src)) << std::endl;
}
void libpcap_test(){
	Libpcap l;
	int num_packets = 100;
	std::cout << COLOR_YELLOW << "Device: " << COLOR_RESET << l.dev  << std::endl;
	l.Sniff(got_packet, "ip", num_packets);
}
