#include "global/globalEnvironment.hpp"
#include "network/sockets/socket.hpp"

int main() {
    Network::Socket socket(-1, SOCK_STREAM, 0, 8080, INADDR_ANY);
    
    return 0;
}
