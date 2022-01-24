
#include <gtest/gtest.h>
#include <filesystem>
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

TEST (TEST_ReadFolder /*test suite name*/, ReturnsFileInfo) {
    namespace fs = std::filesystem;

    // Create directories
//    fs::current_path(fs::temp_directory_path()); // cd /temp
    fs::create_directory("./temp_dir");
    fs::create_directories("./temp_dir/dir1/dir2");
    fs::create_directory("./temp_dir/dir3");

    // Create a file
    std::string file_path = "./temp_dir/dir3/temp_file.txt";
    std::ofstream temp_file;
    temp_file.open(file_path);
    temp_file << "This is line 1 ...\n";
    temp_file << "Now we add line 2 ...\n";
    temp_file << "Then the line 3 ...\n";

    // copy files and folders around
    fs::copy(file_path, "./temp_dir/dir1/dir2/temp_file.txt");
    fs::copy("./temp_dir/dir1", "./temp_dir/dir3");
    const auto copyOptions = fs::copy_options::update_existing
                             | fs::copy_options::recursive
                             | fs::copy_options::directories_only;
    // update file before copying
    temp_file << "Just one more line, that all ;).";

    // notice that previously, we copied the file into this folder
    fs::copy("./temp_dir/dir3", "./temp_dir/dir1/dir2/", copyOptions);

    std::string inFileName = "../src/main.cpp";
    std::string outFileName = "../out_file";

    auto folder_info = ReadFolder("./temp_dir");

    std::system("ls -l ./temp_dir");
    std::system("tree ./temp_dir");

    // cleanup
    fs::remove(file_path);
    fs::remove("./temp_dir/dir1/dir2/temp_file.txt");
//    fs::remove_all("temp_dir");  // Another filesystem bug won't let me do this :(

    ASSERT_EQ (false, folder_info.empty());
}