#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.hpp"

namespace syh {

class ConnectingSocket: public SimpleSocket {
private:
    int connection;
public:
    ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
    void connect_to_network(int socket, struct sockaddr_in address) override;
};

};

#endif