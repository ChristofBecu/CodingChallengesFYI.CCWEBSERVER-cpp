#include "network/servers/server.hpp"

Network::Server::Server(int domain, int service, int protocol, int port, u_long interface, int bklg)
{
    socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
}

Network::ListeningSocket *Network::Server::getSocket()
{
    return socket;
}