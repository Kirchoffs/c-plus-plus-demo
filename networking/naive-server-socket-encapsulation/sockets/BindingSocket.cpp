#include "BindingSocket.hpp"

syh::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface) 
    : SimpleSocket(domain, service, protocol, port, interface) {
    connect_to_network(get_socket(), get_address());
    test_connection(binding);
}

void syh::BindingSocket::connect_to_network(int socket, struct sockaddr_in address) {
    binding = bind(socket, (struct sockaddr *) &address, sizeof(address));
}

int syh::BindingSocket::get_binding() {
    return binding;
}
