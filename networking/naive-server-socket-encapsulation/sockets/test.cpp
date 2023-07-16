#include "ListeningSocket.hpp"

int main() {
    std::cout << "Starting..." << std::endl;

    std::cout << "BindingSocket..." << std::endl;
    syh::BindingSocket binding_socket(AF_INET, SOCK_STREAM, IPPROTO_IP, 8080, INADDR_ANY);
    
    std::cout << "ListeningSocket..." << std::endl;
    syh::ListeningSocket listening_socket(AF_INET, SOCK_STREAM, IPPROTO_IP, 8081, INADDR_ANY, 5);
    
    std::cout << "Success..." << std::endl;
}