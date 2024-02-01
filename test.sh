#!/bin/bash
set -e
clang-tidy fstr.c
gcc -Wall -Werror -DFSTR_NO_SPACE_CB -DFSTR_DEFAULT_CB  fstr.c test.c
./a.out 1>stdout 2>stderr
diff --color stdout.golden stdout
diff --color stderr.golden stderr
rm stdout stderr
