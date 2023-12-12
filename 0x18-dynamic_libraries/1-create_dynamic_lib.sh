#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fpic -c *.c
gcc -shared -o liball.so *.o
