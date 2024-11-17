/**
 * @file socket.cpp
 * @brief Socket class.
 * The Socket class is used to create a socket and set the SO_REUSEADDR option.
 */

#include "network/sockets/socket.hpp"

/**
 * @brief Constructor for the Socket class.
 * The constructor initializes a socket with the specified domain, service, protocol, port, and interface.
 * It sets up the address structure, creates a new socket, and tests the connection.
 * If compiled with DEBUG, it also sets the reuse address option.
 *
 * @param domain The communication domain (e.g., AF_INET for IPv4).
 * @param service The type of service (e.g., SOCK_STREAM for TCP).
 * @param protocol The protocol to be used (e.g., IPPROTO_TCP for TCP).
 * @param port The port number to bind the socket to.
 * @param interface The IP address to bind the socket to (in network byte order).
 */

Network::Socket::Socket(int domain, int service, int protocol, int port, u_long interface)
{
    // Address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // create a new socket
    sock = socket(domain, service, protocol);

    handleSocketError(sock);

#ifdef DEBUG
    std::cout << "setting reuse address option" << std::endl;
    setReuseAddressOption();
#endif
}

void Network::Socket::handleSocketError(int socketItem)
{
    if (socketItem < 0)
    {
        close(sock);
        throw std::runtime_error("Error establishing connection");
    }
}

/**
 * @brief Sets the SO_REUSEADDR option on the socket.
 *
 * This function enables the SO_REUSEADDR option on the socket, which allows
 * the socket to be bound to an address that is already in use. This is useful
 * for applications that need to restart and bind to the same address without
 * waiting for the socket to be released by the operating system.
 *
 * @throws std::runtime_error if the setsockopt call fails.
 */
void Network::Socket::setReuseAddressOption()
{
    int opt = -1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        close(sock);
        throw std::runtime_error("setsockopt(SO_REUSEADDR) failed");
    }
}

// Getters
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

// Setters
void Network::Socket::setConnection(int domain)
{
    connection = domain;
}
