#ifndef KAL_COMPILER_COMMON_HPP
#define KAL_COMPILER_COMMON_HPP

#include "llvm/Support/CommandLine.h"
#include <string>
#include <fstream>


namespace cmd {
bool HandleArgs(const std::string &inFilename, const std::string &outFilename);

}
#endif //KAL_COMPILER_COMMON_HPP
