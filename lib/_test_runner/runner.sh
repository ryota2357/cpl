#!/bin/bash
cd `dirname $0`

for target in $(find ../*/test.cpp)
do
    clang++ -std=c++17 -stdlib=libc++ -Wall -O2 $target
    ./a.out
done
