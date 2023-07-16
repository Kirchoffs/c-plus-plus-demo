#include "SimpleSocket.hpp"

syh::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface) {
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    socket = ::socket(domain, service, protocol);
    test_connection(socket);
}

void syh::SimpleSocket::test_connection(int item_to_connect) {
    if (item_to_connect < 0) {
        perror("Failed to connect...");
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in syh::SimpleSocket::get_address() {
    return address;
}

int syh::SimpleSocket::get_socket() {
    return socket;
}
