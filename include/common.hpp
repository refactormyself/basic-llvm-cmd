#ifndef KAL_COMPILER_COMMON_HPP
#define KAL_COMPILER_COMMON_HPP

#include "llvm/Support/CommandLine.h"
#include <string>
#include <fstream>
#include <ctime>
#include <filesystem>


namespace cmd {
    struct FileInfo {
        std::string filename;
        unsigned long size = 0;
        bool isObjectFile;
        unsigned long numLines = 0; /// for text files
        std::filesystem::file_time_type lastUpdated;
    };

    bool HandleArgs(const std::string &inFilename, const std::string &outFilename);
    FileInfo ReadFile(const std::filesystem::path& filePath);
    std::vector<FileInfo> ReadFolder(const std::string &filePath);
    void CreateReportFile(const std::vector<FileInfo>& files, const std::string &outFilename);
}
#endif //KAL_COMPILER_COMMON_HPP
