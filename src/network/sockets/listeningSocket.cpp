/**
 * @file listeningSocket.cpp
 * @brief ListeningSocket class.
 * The class ListeningSocket is a subclass of the BindingSocket class.
 *
 * The constructor let's the BindingSocket class create a new socket.
 * It then starts to listen server side for incoming connections.
 */

#include "network/sockets/listeningSocket.hpp"

/**
 * @brief Constructor for the ListeningSocket class.
 * The constructor let's the BindingSocket class create and bind a new socket.
 * It then starts to listen server side for incoming connections.
 *
 * @param domain The domain of the socket.
 * @param service The service of the socket.
 * @param protocol The protocol of the socket.
 * @param port The port of the socket.
 * @param interface The interface of the socket.
 * @param bklg The backlog of the socket.
 */
Network::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg)
    : BindingSocket(domain, service, protocol, port, interface)
{
    backlog = bklg;
    startListening();
};

/**
 * @brief Starts listening for incoming connections.
 * The function listens for incoming connections on the socket.
 */

void Network::ListeningSocket::startListening()
{
    listening = listen(getSocket(), backlog);
    handleSocketError(listening);
}

int Network::ListeningSocket::getListening()
{
    return listening;
}