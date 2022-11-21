#!/bin/bash
set -e
mkdir -p bin
gcc tests/main.c -Llib -lTestSuite -Wall -o bin/tests.a
bin/tests.a