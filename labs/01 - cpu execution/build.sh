#!/usr/bin/env sh

set -eu

cc -std=c11 -O2 -Wall -Wextra -pedantic -Iinclude src/*.c -pthread -o cpu_lab
