#include "tests/globalTestEnvironment.hpp"

namespace tests
{
    TEST(ListeningSocketTests, SocketStartListeningSucces)
    {
        Network::ListeningSocket listeningSocket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);

        ASSERT_EQ(listeningSocket.getListening(), 0);
    }

    TEST(ListeningSocketTests, SocketStartListeningFailure)
    {
        int domain = -1; // invalid address family

        ASSERT_EXIT(Network::ListeningSocket listeningSocket(domain, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);, ::testing::ExitedWithCode(1), "Error establishing connection");
    }

} // namespace tests
