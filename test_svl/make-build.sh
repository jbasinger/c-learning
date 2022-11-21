#!/bin/bash
mkdir -p ./obj
mkdir -p ./lib

for srcFile in src/*.c; do
    fileName=$(echo $srcFile | cut -d'/' -f2 | cut -d'.' -f1)
    gcc -Wall -c $srcFile -o ./obj/$fileName.o
done

ar rcs libTestSuite.a ./obj/*.o
mv libTestSuite.a lib/libTestSuite.a
cp -f src/*.h lib
