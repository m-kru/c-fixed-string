#!/bin/bash
set -e
clang-tidy sstr.c
gcc -Wall -Werror -DSSTR_NO_SPACE_CB -DSSTR_DEFAULT_CB  sstr.c test.c
./a.out 1>stdout 2>stderr
diff --color stdout.golden stdout
diff --color stderr.golden stderr
rm stdout stderr
