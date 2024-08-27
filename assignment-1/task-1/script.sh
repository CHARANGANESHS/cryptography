#!/bin/bash

CXX=g++

INCLUDE_DIR="include"
SRC_DIR="src"


OUTPUT="program"


$CXX -std=c++17 \
    -I$INCLUDE_DIR \
    -o $OUTPUT \
    main.cpp \
    $SRC_DIR/writefile.cpp \
    $SRC_DIR/readfile.cpp \
    $SRC_DIR/plain.cpp \
    $SRC_DIR/cipher.cpp \
    $SRC_DIR/vigenere.cpp \

if [ $? -eq 0 ]; then
    echo "Compilation successful."
    # Run the executable
    ./$OUTPUT
else
    echo "Compilation failed."
fi
