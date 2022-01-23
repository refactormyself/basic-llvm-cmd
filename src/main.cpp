#include "llvm/Support/CommandLine.h"

#include "common.hpp"

// #include "llvm/Support/VirtualFileSystem.h"

using namespace llvm;
using namespace std;


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
    bool InteractShellMode = HandleArgs(InputFilename, OutputFilename);
    return 0;
}

