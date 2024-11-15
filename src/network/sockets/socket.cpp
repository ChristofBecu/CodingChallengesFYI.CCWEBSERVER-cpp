#include "network/sockets/socket.hpp"

Network::Socket::Socket(int domain, int service, int protocol, int port, u_long interface)
{
    // Address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // create a new socket
    sock = socket(domain, service, protocol);

    if (sock < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
}

int Network::Socket::getSocket()
{
    return sock;
}

struct sockaddr_in Network::Socket::getAddress()
{
    return address;
}

int Network::Socket::getConnection()
{
    return connection;
}
