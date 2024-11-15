#ifndef NETWORK_SOCKET_HPP
#define NETWORK_SOCKET_HPP

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <arpa/inet.h>

namespace Network
{
    class Socket
    {
    private:
        struct sockaddr_in address;
        int sock;
        int connection;

        void setReuseAddressOption();

    public:
        Socket(int domain, int service, int protocol, int port, u_long interface);
        
        void handleSocketError(int testitem);

        struct sockaddr_in getAddress();
        int getSocket();
        int getConnection();

        void setConnection(int domain);
    };
}

#endif //NETWORK_SOCKET_HPP