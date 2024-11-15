#include "global/globalEnvironment.hpp"

int main() {
    Network::ListeningSocket socket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);

    std::string address = inet_ntoa(socket.getAddress().sin_addr);
    int port = ntohs(socket.getAddress().sin_port);

    std::cout << "Listening on " << address << ":" << port << std::endl; // Listening on 0:8080
    std::cin.get();
    return 0;
}
