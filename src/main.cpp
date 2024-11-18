#include "network/servers/webServer.hpp"

int main()
{
    try
    {
        int port = 8080;
        Network::WebServer server(port);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
