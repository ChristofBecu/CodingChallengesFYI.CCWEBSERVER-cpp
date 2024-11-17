#include "tests/globalTestEnvironment.hpp"

namespace tests
{
    TEST(ListeningSocketTests, ConstructorSucces)
    {
        Network::ListeningSocket listeningSocket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);

        ASSERT_EQ(listeningSocket.getListening(), 0);
    }

    TEST(ListeningSocketTests, ConstructorFailure)
    {
        int domain = -1; // invalid address family
        ASSERT_THROW(Network::ListeningSocket(domain, SOCK_STREAM, 0, 8080, INADDR_ANY, 10), std::runtime_error);
    }
}