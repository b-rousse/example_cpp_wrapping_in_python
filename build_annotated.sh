#!/bin/bash

g++ -fPIC --shared -std=c++11 -Wall temp_conversion.cpp export.cpp \ ###backslash means continue line in bash
    -I${CONDA_PREFIX}/include \ ###-I represents where we find our headers
    -I${CONDA_PREFIX}/include/python3.7m \
    -I${CONDA_PREFIX}/include/eigen3 \
    -L${CONDA_PREFIX}/lib -lpython3.7m \ #-L represents where we find our library, -l is the name of our library.
    -o sss_cpp.so
