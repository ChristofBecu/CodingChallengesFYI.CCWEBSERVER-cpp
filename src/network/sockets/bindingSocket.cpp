/**
 * @file bindingSocket.cpp
 * @brief BindingSocket class.
 * The class BindingSocket is a subclass of the Socket class.
 * It is used to create a socket and bind it to an address.
 */

#include "network/sockets/bindingSocket.hpp"

/**
 * @brief Constructor for the BindingSocket class.
 * The constructor let's the socket class create a new socket.
 * It then binds the created socket to the specified address
 * and tests the connection.
 */
Network::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface)
    : Socket(domain, service, protocol, port, interface)
{
    setConnection(establishConnection(getSocket(), getAddress()));
    handleSocketError(getConnection());
};

/**
 * @brief Establishes a connection between the socket and the address.
 *
 * @param sock The socket to bind.
 * @param address The address to bind the socket to.
 * @return int The return code from the bind function.
 */

int Network::BindingSocket::establishConnection(int sock, struct sockaddr_in address)
{
    int returnCode = ::bind(sock, reinterpret_cast<struct sockaddr *>(&address), sizeof(address));

    handleSocketError(returnCode);
    return returnCode;
}
