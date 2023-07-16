#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <iostream>

namespace syh {

class SimpleSocket {
private:
    struct sockaddr_in address;
    int socket;

public:
    SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
    virtual void connect_to_network(int socket, struct sockaddr_in address) = 0;
    void test_connection(int item_to_test);
    struct sockaddr_in get_address();
    int get_socket();
};

};

#endif