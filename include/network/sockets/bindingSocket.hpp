#ifndef NETWORK_BINDINGSOCKET_HPP
#define NETWORK_BINDINGSOCKET_HPP

#include "network/sockets/bindingSocket.hpp"
#include "network/sockets/socket.hpp"

namespace Network
{
    class BindingSocket : public Socket
    {
    private:
    public:
        BindingSocket(int domain, int service, int protocol, int port, u_long interface);

        int establishConnection(int sock, struct sockaddr_in address);
    };
}

#endif