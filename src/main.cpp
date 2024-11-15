#include "global/globalEnvironment.hpp"
#include "network/sockets/bindingSocket.hpp"

int main() {
    Network::BindingSocket socket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);

    std::cout << socket.getSocket() << std::endl; // Socket: 3
    
    return 0;
}
