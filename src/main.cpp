#include "network/servers/webServer.hpp"
#include <csignal>

Network::WebServer *serverPtr = nullptr;

void signalHandler(int signum)
{
    std::cout << "Interrupt signal (" << signum << ") received." << std::endl;
    std::cout << "Shutting down server." << std::endl;

    delete serverPtr;
    serverPtr = nullptr;

    exit(signum);
}

void deleteServerPtr()
{
    if (serverPtr != nullptr)
    {
        std::cout << "Shutting down server." << std::endl;
        delete serverPtr; // This should close the socket and free the port
        serverPtr = nullptr;
    }
}
int main()
{
    // Register signal handler for SIGINT (Ctrl+C)
    std::signal(SIGINT, signalHandler);

    try
    {
        int port = 8087;
        serverPtr = new Network::WebServer(port);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        deleteServerPtr();
        return EXIT_FAILURE;
    }

    deleteServerPtr();
    return EXIT_SUCCESS;
}
