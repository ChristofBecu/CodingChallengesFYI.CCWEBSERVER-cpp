#include "global/globalEnvironment.hpp"
#include <unistd.h>

int main() {
    try
    {
        Network::ListeningSocket socket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);

        std::string address = inet_ntoa(socket.getAddress().sin_addr);
        int port = ntohs(socket.getAddress().sin_port);
        std::cout << "listening : " << socket.getListening() << std::endl; // listening : 0

        std::cout << "Listening on " << address << ":" << port << std::endl; // Listening on 0:8080
        std::cin.get();
        close(socket.getSocket());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
