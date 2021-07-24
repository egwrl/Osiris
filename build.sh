#!/usr/bin/env bash


mkdir Release && cd Release && cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_C_COMPILER=gcc-10 -D CMAKE_CXX_COMPILER=g++-10 ..

make -j $(nproc --all)

mv libOsiris.so ..
