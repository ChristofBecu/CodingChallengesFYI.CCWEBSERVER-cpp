#include "tests/globalTestEnvironment.hpp"

namespace tests
{
    TEST(bindingSocketTest, establishConnectionSucces) {
        Network::BindingSocket bs(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);
        ASSERT_GE(bs.getConnection(), 0);
    }

    TEST(bindingSocketTest, establishConnectionFailure) {
        int domain = -1; // invalid address family

        ASSERT_EXIT(Network::BindingSocket bs(domain, SOCK_STREAM, 0, 8080, INADDR_ANY);, ::testing::ExitedWithCode(1), "Error establishing connection");
    }
}
