#!/bin/env bash

mkdir build && cd build

# change sdk path if differs
PICO_SDK_PATH=/usr/share/pico-sdk cmake ..

make

echo 'Your generated .uf2 is at ./build/src/'
