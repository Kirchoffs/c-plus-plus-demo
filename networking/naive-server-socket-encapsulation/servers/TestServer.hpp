#ifndef TestServer_hpp
#define TestServer_hpp

#include <stdio.h>

#include "SimpleServer.hpp"

namespace syh {

class TestServer: public SimpleServer {
private:
    char buffer[30000] = {0};
    int accept_socket;
    
    void accepter();
    void handler();
    void responder();
public:
    TestServer();
    void launch();
};

};

#endif