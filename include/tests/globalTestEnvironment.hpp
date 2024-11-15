#ifndef GLOBAL_TEST_ENVIRONMENT_HPP
#define GLOBAL_TEST_ENVIRONMENT_HPP

#include <gtest/gtest.h>

#include "global/globalEnvironment.hpp"

class GlobalTestEnvironment : public ::testing::Environment {
public:
    void SetUp() override;
    void TearDown() override;
};

#endif // GLOBAL_TEST_ENVIRONMENT_HPP