#!/bin/bash


CXX=g++

INCLUDE_DIR="include"
SRC_DIR="src"

OUTPUT="program"

$CXX -std=c++17 \
    -I$INCLUDE_DIR \
    -o $OUTPUT \
    main.cpp \
    $SRC_DIR/cipher.cpp \
    $SRC_DIR/readfile.cpp \
    $SRC_DIR/vigenere.cpp \
    $SRC_DIR/writefile.cpp \

if [ $? -eq 0 ]; then
    echo "Compilation successful."
    ./$OUTPUT
else
    echo "Compilation failed."
fi
