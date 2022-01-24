### A basic command line project based on [LLVM's Command Line]() tool

This is the first in a series of small minimal demo of llvm internal tools that are aimed at internal use.

Here I demonstrated the use of the Command Line Utility use by all llvm projects. It is a powerful tool for
handling commandline arguments passed into an application. It bears huge similarity to [the CLI11 tool, demoed here.](https://github.com/refactormyself/basic-cli-util)

If you are developing a project with dependency on llvm, you would like to LLVM's Command Line tool.

### - Why I created this :
I need a quick bootstrap app for a working on LLVM stuffs.

### - To try it out
```shell
sh ./build_run.sh $LLVM_INSTALL_DIR
```

### - What does this do:
- It optionally accepts two file path    
  `$ cmd-ap-boot "input-file" -o "outputfile"`
- If the output file (in Markdown format) is supplied it prints out a "File information" report of the files in the same folder with the supplied file.
  Otherwise, the source folder is used to generate a report.
- There are also some trivial Google Tests
- Example of Report:

| **FILE NAME** | **SIZE** | **NUM OF LINES** | **LAST UPDATED**         |
|---------------|----------|------------------|--------------------------|
| main.cpp      | 1311     | 42               | Mon Jan 24 10:04:42 2022 |
| tmp.cpp       | 963      | 27               | Sun Jan 16 17:52:09 2022 |
| common.cpp    | 3238     | 87               | Mon Jan 24 10:24:23 2022 |
| Parser1.cpp   | 5158     | 200              | Mon Jan  3 14:12:41 2022 |

### - A few concepts demonstrated 
- Handling command line arguments
- Create an LLVM based project out of the tree (the CMakeList setup)
- Using Google's Gtest suite
- Using C++ STD API for file and folder handling (C++ 17 required)