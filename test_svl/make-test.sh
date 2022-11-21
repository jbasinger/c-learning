#!/bin/bash
set -e
gcc tests/main.c -Llib -lTestSuite -Wall -o tests.a
./tests.a