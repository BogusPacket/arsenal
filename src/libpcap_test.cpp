#include "../includes/arsenal.h"
#include "../includes/libpcap.h"

void got_packet(u_char* args, const struct pcap_pkthdr *header, const u_char *packet){
	struct IPv4 ip;
	memcpy(&ip.vhl, &packet + 14, sizeof(struct IPv4));
	std::cout << IPv4_i2s(IPv4_n2h(ip.dst)) << std::endl;
}
void libpcap_test(){
	Libpcap l;
	int num_packets = 10;
	std::cout << COLOR_YELLOW << "Device: " << COLOR_RESET << l.dev  << std::endl;
	pcap_loop(l.handle, num_packets, got_packet, NULL);
}
