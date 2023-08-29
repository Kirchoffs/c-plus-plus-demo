#include "ConnectingSocket.hpp"

syh::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface)
    : SimpleSocket(domain, service, protocol, port, interface) 
{
    connect_to_network(get_socket(), get_address());
    test_connection(connection);
}

void syh::ConnectingSocket::connect_to_network(int socket, struct sockaddr_in address) 
{
    connection = connect(socket, (struct sockaddr *) &address, sizeof(address));
}