#!/bin/bash
set -e

mkdir -p bin

cc -fPIC -shared -o bin/libroll.so \
  roll.c
