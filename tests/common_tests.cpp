
#include <gtest/gtest.h>
#include "common.hpp"

using namespace cmd;

TEST (HandleArgs /*test suite name*/, NoInputFile /*test name*/) {
    std::string inFileName;
    std::string outFileName = "../out_file";

    EXPECT_TRUE(inFileName.empty());
    EXPECT_FALSE(outFileName.empty());

    bool replMode = HandleArgs(inFileName, outFileName);

    ASSERT_EQ (true, replMode);  // drop to repl mode
}

TEST (HandleArgs, NoOutputFile) {
    std::string inFileName;
    std::string outFileName;

    EXPECT_TRUE(inFileName.empty());
    EXPECT_TRUE(outFileName.empty());

    bool replMode = HandleArgs(inFileName, outFileName);

    ASSERT_EQ (true, replMode);  // drop to repl, output file has no effect
}

TEST (HandleArgs, NoInputFile_with_dash) {
    std::string inFileName = "-";
    std::string outFileName;

    EXPECT_FALSE(inFileName.empty());
    EXPECT_TRUE(outFileName.empty());

    bool replMode = HandleArgs(inFileName, outFileName);

    ASSERT_EQ (true, replMode);  // drop to repl
}

TEST (HandleArgs /*test suite name*/, HasInputFile) {
    std::string inFileName = "../src/main.cpp";
    std::string outFileName = "../out_file";

    EXPECT_FALSE(inFileName.empty());
    EXPECT_FALSE(outFileName.empty());

    bool replMode = HandleArgs(inFileName, outFileName);

    ASSERT_EQ (false, replMode);
}
