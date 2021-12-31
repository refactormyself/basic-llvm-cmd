#include "llvm/Support/CommandLine.h"
#include <fstream>

// #include "llvm/Support/VirtualFileSystem.h"

using namespace llvm;
using namespace std;

bool InteractShellMode = false;

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

   
    if (InputFilename == "-")
    {
        outs() << "Blank! No file name supplied.\nSwitching to Interactive Shell Mode.\n";
        InteractShellMode = true;
    }
    
    if (!InteractShellMode) {
        std::ofstream Input(InputFilename.c_str());
        if (Input.good())
        {
            outs() << "Yep, I can read the file " << InputFilename << " \n";
        } else {
            outs() << "Error: There is a problem reading the file " 
                   << InputFilename << " ! \n";
        }
    }

   return 0;
}