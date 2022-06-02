#include "common.hpp"
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>


namespace cmd {
    using namespace llvm;
    using namespace std;
    namespace fs = std::filesystem;

    bool HandleArgs(const std::string &inFilename, const std::string &outFilename) {
        bool replMode = false;
        if (inFilename == "-" || inFilename.empty()) {
            outs() << "Blank! No file name supplied.\nSwitching to Interactive Shell Mode.\n";
            replMode = true;
        }

        return replMode;
    }

    FileInfo ReadFile(const fs::path &filePath) {
        std::ifstream fileStrm;
        fileStrm.open(filePath);
        if(!fileStrm) {
            std::cerr << "Error: Unable to open the file: "<< filePath << std::endl;
            exit(1);
        } else outs() << "Yep, I can read the file " << filePath << " \n";

        FileInfo fileInfo;
//        if (exists(filePath)) {
            fileInfo.filename = filePath.filename();
            fileInfo.lastUpdated = fs::last_write_time(filePath);
            fileInfo.size = fs::file_size(filePath);
            fileInfo.numLines = std::count(std::istreambuf_iterator<char>(fileStrm),
                                           std::istreambuf_iterator<char>(), '\n');
//        } else std::cerr << "cannot access file " << filePath << '\n';

        return fileInfo;
    }

    std::vector<FileInfo> ReadFolder(const string &filePath) {
        std::vector<FileInfo> filesInFolder;
        for (const auto &file: fs::directory_iterator(filePath)) {
            if (file.is_regular_file()) {
                auto fileInfo = ReadFile(file.path());
                if (!fileInfo.filename.empty())
                    filesInFolder.push_back(fileInfo);
            }
            if (file.is_directory()) {
                auto temp = ReadFolder(file.path());
                filesInFolder.insert(filesInFolder.end(), temp.begin(), temp.end());
            }
        }
        return filesInFolder;
    }

    // ref: https://en.cppreference.com/w/cpp/filesystem/directory_entry/last_write_time
    std::string to_string(std::filesystem::file_time_type const &ftime) {
//        std::time_t cftime = std::chrono::system_clock::to_time_t(ftime);
//               // std::chrono::file_clock::to_sys(ftime));
//        std::string str = std::asctime(std::localtime(&cftime));
//        str.pop_back();  // rm the trailing '\n' put by `asctime`
//        return str;
        return ""; // TODO: there is a wierd bug here ^^^^
    }

    void CreateReportFile(const std::vector<FileInfo> &files, const string &outFilename) {
        fs::path outputFile;
        if (fs::exists(outFilename))
            outputFile = outFilename;
        else {
            fs::path file = "file_info_report.md";
            outputFile = fs::current_path() / file;
        }

        std::ofstream stream(outputFile);
        stream << "### This is the report on the files in your folder.\n\n\n";
        stream << "**FILE NAME** | **SIZE** | **NUM OF LINES** | **LAST UPDATED**\n";
        stream << "--- | --- | --- | --- \n";
        for (const auto &file: files) {
            stream << file.filename << " | " << file.size << " | "
                    << file.numLines  << " | " << to_string(file.lastUpdated) << '\n';
        }

        std::cout << "Report has been written to " << outputFile << '\n';
    }
}