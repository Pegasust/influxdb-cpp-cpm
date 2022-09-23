#!/usr/bin/env bash

set -ex
# assume that we're on project root

cmake -S all -B build
cmake -S all -B build -DCMAKE_EXPORT_COMPILE_COMMANDS:bool=true
cp build/compile_commands.json ./

cmake --build build

