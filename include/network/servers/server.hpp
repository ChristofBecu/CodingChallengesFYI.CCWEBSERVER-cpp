#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <unistd.h>
#include "network/sockets/libSockets.hpp"

namespace Network
{
    class Server
    {
    private:
        ListeningSocket *socket;
        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;
        virtual void launch() = 0;

    public:
        Server(int domain, int service, int protocol, int port, u_long interface, int bklg);
        ListeningSocket *getSocket();
    };
};

#endif // SERVER_H