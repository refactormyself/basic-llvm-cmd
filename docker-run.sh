#!/usr/bin/env bash

DCKR_FILE=./x86.Dockerfile
DCKR_IMAGE="x86-basic-llvm-x86"
DCKR_CONTAINER="x86-running-llvm-cli-x86"

docker build -t $DCKR_IMAGE -f $DCKR_FILE .
docker run --rm \
        --name $DCKR_CONTAINER \
        $DCKR_IMAGE

#        -v "${PWD}:/app_src" -w "/app_src" \
