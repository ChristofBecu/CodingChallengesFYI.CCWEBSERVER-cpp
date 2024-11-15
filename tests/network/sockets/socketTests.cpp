#include "tests/globalTestEnvironment.hpp"
#include "network/sockets/socket.hpp"

Network::Socket s = Network::Socket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);

namespace
{
    TEST(socketTest, addressStructure)
    {
        struct sockaddr_in address = s.getAddress();

        ASSERT_EQ(address.sin_family, AF_INET);
        ASSERT_EQ(ntohs(address.sin_port), 8080);
        ASSERT_STREQ(inet_ntoa(address.sin_addr), "0.0.0.0");
    }

    TEST(socketTest, socketCreationSuccess)
    {
        ASSERT_GE(s.getSocket(), 0);
    }

    TEST(socketTest, socketCreationFailure)
    {
        int domain = -1; // invalid address family

        ASSERT_EXIT(Network::Socket(domain, SOCK_STREAM, 0, 8080, INADDR_ANY), ::testing::ExitedWithCode(1), "Error establishing connection");
    }

    TEST(socketTest, getSocketReturnsInt) {
        int sock = s.getSocket();

        ASSERT_EQ(typeid(sock), typeid(int));
    }

    TEST(socketTest, getAddressReturnsStruct) {
        struct sockaddr_in address = s.getAddress();

        ASSERT_EQ(typeid(address), typeid(struct sockaddr_in));
    }

    TEST(socketTest, getConnectionReturnsInt) {
        int connection = s.getConnection();

        ASSERT_EQ(typeid(connection), typeid(int));
    }
}
