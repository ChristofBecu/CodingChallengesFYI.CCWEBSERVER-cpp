#include "tests/globalTestEnvironment.hpp"

GlobalTestEnvironment *env = nullptr;

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    env = static_cast<GlobalTestEnvironment *>(testing::AddGlobalTestEnvironment(new GlobalTestEnvironment));
    return RUN_ALL_TESTS();
}