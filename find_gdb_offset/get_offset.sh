#!/bin/sh

set -e
set -x

make
gcc -lc test_offset.o print_offset.c -o print_offset
./print_offset
