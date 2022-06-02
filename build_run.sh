#!/usr/bin/env bash

if [ "" == "$1" ]; then
    echo "Please pass in the install location of llvm."
    echo "(It is advised to build llvm from source.)"
    exit
fi

HERE=$PWD

rm -rf "$HERE"/build || echo "rm failed for $HERE/build"
mkdir build
cd build || exit

cmake .. -DLT_LLVM_INSTALL_DIR="$1"
make
#make test

./cmd-app-boot
./tests/common_tests

cd "$HERE" || exit