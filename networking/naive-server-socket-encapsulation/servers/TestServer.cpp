#include "TestServer.hpp"

syh::TestServer::TestServer(): SimpleServer(AF_INET, SOCK_STREAM, IPPROTO_IP, 8080, INADDR_ANY, 10) {
    launch();
}

void syh::TestServer::launch() {
    while (true)
    {
        std::cout << "========== WAITING ==========" << std::endl;

        accepter();
        handler();
        responder();

        std::cout << "========== DONE ==========" << std::endl;
    }
}

void syh::TestServer::accepter() {
    ListeningSocket *listening_socket = get_listeing_socket();
    
    struct sockaddr_in address = listening_socket->get_address();
    int address_length = sizeof(address);

    accept_socket = accept(
        listening_socket->get_socket(), 
        (struct sockaddr *) &address, 
        (socklen_t*) &address_length
    );

    read(accept_socket, buffer, 30000);
}

void syh::TestServer::handler() {
    std::cout << buffer << std::endl;
}

void syh::TestServer::responder() {
    char const *hello = "Hello World";
    write(accept_socket, hello, strlen(hello));
    close(accept_socket);
}
