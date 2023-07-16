#include "SimpleServer.hpp"

syh::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int backlog) {
    listening_socket = new ListeningSocket(domain, service, protocol, port, interface, backlog);
}

syh::ListeningSocket *syh::SimpleServer::get_listeing_socket() {
    return listening_socket;
}

syh::SimpleServer::~SimpleServer() {
    delete listening_socket;
}