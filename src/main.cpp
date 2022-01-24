#include "llvm/Support/CommandLine.h"
#include <filesystem>

#include "common.hpp"

// #include "llvm/Support/VirtualFileSystem.h"

using namespace llvm;
using namespace std;
using namespace cmd;
namespace fs = std::filesystem;

// -o <filename>
cl::opt<string> OutputFilename("o", cl::desc("Specify output filename"), cl::value_desc("filename"));

// <input file>
cl::opt<string> InputFilename(cl::Positional, cl::desc("<input file>"), cl::init("-"));
// <input file> (required)
// cl::opt<string> InputFilename(cl::Positional, cl::desc("<input file>"), cl::Required);


int main(int argc, char **argv)
{
    //   cl::ParseCommandLineOptions(argc, argv);

    cl::ParseCommandLineOptions(argc, argv, " A basic use of LLVM CommandLine \n\n"
                                            "  This program is an example of blah blah blah...\n");
    bool InteractShellMode = cmd::HandleArgs(InputFilename, OutputFilename);

    fs::path file, ouputFile;
    if (InteractShellMode) // at least no input file
        file = "../src/main.cpp";
    else
        file = InputFilename.c_str();

    auto fileInfo = cmd::ReadFile(file);
//    auto allFiles = cmd::ReadFolder(fs::current_path());
    auto allFiles = cmd::ReadFolder(file.parent_path());
    cmd::CreateReportFile(allFiles, OutputFilename);
    return 0;
}

