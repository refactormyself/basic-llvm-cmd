cmake_minimum_required(VERSION 3.13.4)
project(kal-compiler LANGUAGES CXX C)

set(CMAKE_BUILD_WITH_INSTALL_NAME_DIR ON)
set(CMAKE_CXX_STANDARD 14 CACHE STRING "C++ standard to conform to")

message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/bin)
set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/lib)

# Pass in the local LLVM installation directory (Please build LLVM from source)
set(LT_LLVM_INSTALL_DIR "" CACHE PATH "LLVM installation directory")

# Tell CMake the location of LLVMConfig.cmake so find_package is not lost :(
list(APPEND CMAKE_PREFIX_PATH "${LT_LLVM_INSTALL_DIR}/lib/cmake/llvm/")
# list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")

find_package(LLVM REQUIRED CONFIG)

include_directories(SYSTEM ${LLVM_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_BINARY_DIR}/include)
link_directories(${LLVM_BUILD_LIBRARY_DIR})
add_definitions(${LLVM_DEFINITIONS})

# To avoid the linker error:
# undefined reference to `typeinfo for llvm::cl::GenericOptionValue'
if(NOT LLVM_ENABLE_RTTI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

add_executable(
    kal
    src/main.cpp
)

# To avoid undefined reference to `llvm::EnableABIBreakingChecks'
# ref: https://stackoverflow.com/a/63499379
target_link_libraries(kal LLVMSupport)
