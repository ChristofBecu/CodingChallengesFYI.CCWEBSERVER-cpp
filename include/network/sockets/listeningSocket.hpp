#ifndef NETWORK_LISTENINGSOCKET_HPP
#define NETWORK_LISTENINGSOCKET_HPP

#include <stdio.h>
#include "network/sockets/bindingSocket.hpp"

namespace Network
{
    class ListeningSocket : public BindingSocket
    {
    private:
        int backlog;
        int listening;
    public:
        ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg);

        void startListening();

        int getListening();
    };
}

#endif //NETWORK_LISTENINGSOCKET_HPP