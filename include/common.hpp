#ifndef KAL_COMPILER_COMMON_HPP
#define KAL_COMPILER_COMMON_HPP

#include "llvm/Support/CommandLine.h"
#include <string>
#include <fstream>
#include <ctime>


namespace cmd {
    struct FileInfo {
        std::string filename;
        int size;
        bool isObjectFile;
        long numLines; /// for text files
        std::time_t lastUpdated;
    };

    bool HandleArgs(const std::string &inFilename, const std::string &outFilename);
    FileInfo ReadFile(const std::string &filePath);
    std::vector<FileInfo> ReadFolder(const std::string &filePath);
    void CreateReportFile(std::vector<FileInfo>, const std::string &outFilename);
}
#endif //KAL_COMPILER_COMMON_HPP
