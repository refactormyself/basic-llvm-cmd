
#include <gtest/gtest.h>

// I need to add custom main to test ...
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}