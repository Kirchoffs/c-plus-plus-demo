#include "ListeningSocket.hpp"

syh::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog) 
    : BindingSocket(domain, service, protocol, port, interface) {
    this->backlog = backlog;
    start_listening();
    test_connection(listening);
}

void syh::ListeningSocket::start_listening() {
    listening = listen(get_socket(), backlog);
}

int syh::ListeningSocket::get_listening() {
    return listening;
}

int syh::ListeningSocket::get_backlog() {
    return backlog;
}
