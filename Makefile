all:
	g++ arsenal.cpp src/converter.cpp src/libpcap_test.cpp -lnet -lpcap -o arsenal


