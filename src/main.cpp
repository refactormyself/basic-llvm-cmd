#include "llvm/Support/CommandLine.h"
#include <fstream>

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

bool HandleArgs(const std::string& inFilename, const std::string& outFilename) {
    bool  replMode = false;
    if (inFilename == "-")
    {
        outs() << "Blank! No file name supplied.\nSwitching to Interactive Shell Mode.\n";
        replMode = true;
    }

    if (!replMode) {
        ofstream Input(inFilename.c_str());
        if (Input.good())
        {
            outs() << "Yep, I can read the file " << inFilename << " \n";
        } else {
            outs() << "Error: There is a problem reading the file "
                   << inFilename << " ! \n";
        }
    }
    return  replMode;
}
