#include "common.hpp"

using namespace llvm;
using namespace std;
//using namespace cmd;
namespace cmd {
    bool HandleArgs(const std::string &inFilename, const std::string &outFilename) {
        bool replMode = false;
        if (inFilename == "-") {
            outs() << "Blank! No file name supplied.\nSwitching to Interactive Shell Mode.\n";
            replMode = true;
        }

        if (!replMode) {
            ofstream Input(inFilename.c_str());
            if (Input.good()) {
                outs() << "Yep, I can read the file " << inFilename << " \n";
            } else {
                outs() << "Error: There is a problem reading the file "
                       << inFilename << " ! \n";
            }
        }
        return replMode;
    }

    FileInfo ReadFile(const string &filePath) {
        return FileInfo();
    }

    std::vector<FileInfo> ReadFolder(const string &filePath) {
        return std::vector<FileInfo>();
    }

    void CreateReportFile(std::vector<FileInfo>, const string &outFilename) {

    }
}