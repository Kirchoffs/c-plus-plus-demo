# Notes

## Project Notes
Basic steps for server:
```
int sock_fd, accept_fd, len;
struct sockaddr_in addr;

// socket create and verification
sock_fd = socket(AF_INET, SOCK_STREAM, 0);
if (sock_fd == -1)
{
    printf("socket creation failed...\n");
    exit(0);
}
else
{
    printf("Socket successfully created..\n");
}
    
bzero(&addr, sizeof(addr));
// assign IP, PORT
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = htonl(INADDR_ANY);
addr.sin_port = htons(PORT);

// Binding newly created socket to given IP and verification
if ((bind(sockfd, (SA*)&addr, sizeof(addr))) != 0)
{
    printf("socket bind failed...\n");
    exit(0);
}
else
{
    printf("Socket successfully binded..\n");
}
    
// Server is ready to listen and verification
if ((listen(sock_fd, 5)) != 0)
{
    printf("Listen failed...\n");
    exit(0);
}
else
{
    printf("Server listening..\n");
}

// Accept the data packet from client and verification
accept_fd = accept(sockfd, (SA*)&cli, &len);
if (accept_fd < 0)
{
    printf("server accept failed...\n");
    exit(0);
}
else
{
    printf("server accept the client...\n");
}
```

Basic steps for client:
```
int sock_fd;
struct sockaddr_in addr;

// socket create and verification
sock_fd = socket(AF_INET, SOCK_STREAM, 0);
if (sock_fd == -1)
{
    printf("socket creation failed...\n");
    exit(0);
}
else
{
    printf("Socket successfully created..\n");
}
    
bzero(&addr, sizeof(addr));
// assign IP, PORT
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = inet_addr("127.0.0.1");
addr.sin_port = htons(PORT);

// connect the client socket to server socket
if (connect(sock_fd, (SA*)&addr, sizeof(addr)) != 0)
{
    printf("connection with the server failed...\n");
    exit(0);
}
else
{
    printf("connected to the server..\n");
}
```

## Test
### Test Sockets
```
>> clang++ -std=c++11 sockets/test.cpp sockets/SimpleSocket.cpp sockets/BindingSocket.cpp sockets/ListeningSocket.cpp -o test
>> ./test
```

### Test Server
```
>> clang++ -std=c++11 servers/test.cpp servers/TestServer.cpp servers/SimpleServer.cpp sockets/SimpleSocket.cpp sockets/BindingSocket.cpp sockets/ListeningSocket.cpp -o test
```

## Virtual Function
A virtual function is a function that can be overridden by a derived class.

The base class declares a virtual function with the virtual keyword, and the derived class can provide its own implementation of that function.

A pure virtual function is a virtual function that has __no implementation in the base class__.

The base class declares a pure virtual function using the virtual keyword followed by = 0 in the function declaration.

## Endianness
Keywords: endianness, htonl, htons

Endianness means that the bytes in computer memory are read in a certain order.

The htonl() function converts the unsigned integer hostlong from host byte order to network byte order.

The htons() function converts the unsigned short integer hostshort from host byte order to network byte order.

The TCP/IP standard network byte order is __big-endian__. In order to participate in a TCP/IP network, little-endian systems usually bear the burden of conversion to network byte order.

## Override
The override keyword is used to explicitly indicate that a function in a derived class is intended to override a virtual function from its base class. It is a way of explicitly specifying the intent of the programmer and helps improve code readability and maintainability.

## Network
```
syh::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    socket = ::socket(domain, service, protocol);
    test_connection(socket);
}
```

__domain__: This parameter represents the communication domain or address family of the socket. It specifies the protocol family that will be used for communication. Common values include:

- AF_INET for IPv4 Internet protocols
- AF_INET6 for IPv6 Internet protocols
- AF_UNIX for Unix domain protocols

__service__: This parameter typically corresponds to the socket type, indicating the semantics of the socket. Common values include:

- SOCK_STREAM for TCP (a reliable, stream-oriented connection).
- SOCK_DGRAM for UDP (an unreliable, datagram-oriented connection).
- SOCK_RAW for raw socket communication.

__protocol__: This parameter specifies the protocol to be used. For example, if you're using IPv4, you might use IPPROTO_TCP for TCP or IPPROTO_UDP for UDP.

__port__: This parameter represents the port number that the socket will be bound to or will connect to. Ports are endpoints for communication in networking, and different applications use different port numbers to communicate.

__interface__: This parameter appears to represent the network interface's IP address. It's being used to configure the IP address for the socket to bind or connect to. The htonl function is likely used to convert the IP address from host byte order to network byte order.

## Cast
`struct sockaddr_in *` to `struct sockaddr *`

## Error
### perror
`perror` is a standard library function used for printing descriptive error messages to the standard error stream (stderr). It is typically used when a function call fails and sets __errno__, which is an integer variable that indicates the type of error that occurred.

```
void perror(const char *str);
```