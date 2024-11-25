#include "network/servers/webServer.hpp"
#include <csignal>
#include "cliArgs/options.hpp"

Network::WebServer *serverPtr = nullptr;

void signalHandler(int signum)
{
    std::cout << " Interrupt signal (" << signum << ") received : Shutting down server." << std::endl;

    delete serverPtr;
    serverPtr = nullptr;

    exit(signum);
}

void deleteServerPtr()
{
    if (serverPtr != nullptr)
    {
        std::cout << "Shutting down server." << std::endl;
        delete serverPtr;
        serverPtr = nullptr;
    }
}

int main(int argc, char *argv[])
{
    // Register signal handler for SIGINT (Ctrl+C)
    std::signal(SIGINT, signalHandler);

    int port;

    CliArguments::parseArguments(argc, argv);

    if (CliArguments::port.empty())
    {
        port = 8008; // Set default port to 8008
    }
    else
    {
        port = std::stoi(CliArguments::port);
        if (port < 1024)
        {
            std::cout << "Ports below 1024 are considered reserved for system services." << std::endl;
            std::cout << "Please choose a port above 1024." << std::endl;
            return EXIT_FAILURE;
        }
    }

    try
    {
        serverPtr = new Network::WebServer(port);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        deleteServerPtr();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
