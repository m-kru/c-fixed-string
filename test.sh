#!/bin/bash
set -e
gcc -DSSTR_NO_SPACE_CB -DSSTR_DEFAULT_CB  sstr.c test.c
./a.out
