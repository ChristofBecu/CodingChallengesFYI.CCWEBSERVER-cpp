#include "tests/globalTestEnvironment.hpp"

namespace tests
{
    TEST(bindingSocketTest, establishConnectionSucces) 
    {
        Network::BindingSocket bs(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);
        ASSERT_GE(bs.getConnection(), 0);
    }

    TEST(bindingSocketTest, establishConnectionFailure) 
    {
        int domain = -1; // invalid address family
        ASSERT_THROW(Network::Socket(domain, SOCK_STREAM, 0, 8080, INADDR_ANY), std::runtime_error);
    }
}
