#!/bin/bash
set -e
clang-tidy sstr.c
gcc -Wall -Werror -DSSTR_NO_SPACE_CB -DSSTR_DEFAULT_CB  sstr.c test.c
./a.out
