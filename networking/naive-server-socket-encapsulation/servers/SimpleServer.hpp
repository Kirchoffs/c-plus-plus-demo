#ifndef SimpleServer_hpp
#define SimpleServer_hpp

#include <stdio.h>
#include <unistd.h>

#include "../sockets/syh-sockets.hpp"

namespace syh {

class SimpleServer {
    
private:
    ListeningSocket *listening_socket;
    virtual void accepter() = 0;
    virtual void handler() = 0;
    virtual void responder() = 0;    

public:
    SimpleServer(int domain, int service, int protocol, int port, u_long interface, int backlog);
    ~SimpleServer();
    virtual void launch() = 0;
    ListeningSocket *get_listeing_socket();
};

};

#endif