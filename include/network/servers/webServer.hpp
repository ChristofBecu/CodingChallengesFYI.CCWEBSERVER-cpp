#ifndef WEBSERVER_HPP
#define WEBSERVER_HPP

#include "network/servers/server.hpp"
#include "network/http/request.hpp"
#include "network/http/response.hpp"
#include <string.h>
#include <fstream>

namespace Network
{
    class WebServer : public Server
    {
    private:
        char buffer[30000] = {0};
        int newSocket;
        std::string httpResponse;
        std::string requestedPath;

        void accepter();
        void handler();
        void responder();
        void launch();

    public:
        WebServer(int port);
    };
}

#endif
