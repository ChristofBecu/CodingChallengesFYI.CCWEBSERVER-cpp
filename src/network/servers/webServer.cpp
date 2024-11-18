#include "network/servers/webServer.hpp"

Network::WebServer::WebServer(int port) : Server(AF_INET, SOCK_STREAM, 0, port, INADDR_ANY, 10)
{
    launch();
}

void Network::WebServer::accepter()
{
    struct sockaddr_in address = getSocket()->getAddress();
    int addrlen = sizeof(address);
    newSocket = accept(getSocket()->getSocket(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
    read(newSocket, buffer, 30000);
}

void Network::WebServer::handler()
{
    Http::Request request(buffer);

    std::string method = request.getMethod();
    std::string uri = request.getUri();
    std::string protocol = request.getProtocol();

#ifdef DEBUG
    std::cout << "Incoming request" << std::endl;
    std::cout << "Method: " << method << std::endl;
    std::cout << "URI: " << uri << std::endl;
    std::cout << "Protocol: " << protocol << std::endl
              << std::endl;
#endif

    Http::Response response = Http::Response(method, uri, protocol);
    //
    httpResponse = response.getResponse();
}

void Network::WebServer::responder()
{
    send(newSocket, httpResponse.c_str(), httpResponse.length(), 0);
    close(newSocket);
}

void Network::WebServer::launch()
{
    struct sockaddr_in address = getSocket()->getAddress();
    std::cout << "Server listening for connections on " << inet_ntoa(address.sin_addr) << ":" << ntohs(address.sin_port) << std::endl;

    while (true)
    {
        accepter();
        handler();
        responder();
    }
}
