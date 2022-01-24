
set(src
        common_tests.cpp main.cpp ../src/common.cpp)



# Get Google Test
enable_testing()
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#add_subdirectory(${CMAKE_BINARY_DIR}/googletest)


add_executable(common_tests ${src})

#include_directories("${gtest_basic1_SOURCE_DIR}/include")
include_directories("../include")

# Link with google test libraries as well as simple-lib
target_link_libraries(common_tests gtest)
target_link_libraries(common_tests gtest_main)
target_link_libraries(common_tests LLVMSupport)
target_link_libraries(common_tests stdc++fs)

# Your milage may vary with the COMMAND
add_test(
        NAME main_tests
        #        COMMAND build/tests/slib_test
        COMMAND common_tests
        #        WORKING_DIRECTORY ${simple-lib_SOURCE_DIR}
)

#
#target_link_libraries(cmd-app-test
#        LLVMSupport
#        gtest
#        gtest_main
#)
#
#add_test(
#        NAME cmd_app_boot
#        COMMAND cmd-app-boot
#)
