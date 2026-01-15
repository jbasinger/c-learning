#!/bin/bash
set -e

./build.sh

cc -o roll_test \
  -L bin \
  -lroll \
  roll_test.c

./roll_test
