# C++ Memory Usage Analyzer

This project analyzes memory usage during dynamic memory allocation in C++.

The program continuously allocates memory using a growing vector and measures
the memory consumption using the Linux system call `getrusage`.

## Features

- dynamic memory allocation experiment
- memory usage monitoring
- resource tracking with getrusage

## Compile

g++ -std=c++17 memory.cpp -o memory_analyzer

## Run

./memory_analyzer
