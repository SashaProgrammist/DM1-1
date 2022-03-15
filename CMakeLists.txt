cmake_minimum_required(VERSION 3.21)
project(1.1 C)

set(CMAKE_C_STANDARD 99)

add_executable(1.1 main.c
        bitset/bitset.h bitset/bitset.c
        ordered_array_set/ordered_array_set.h ordered_array_set/ordered_array_set.c
        unordered_array_set/unordered_array_set.h unordered_array_set/unordered_array_set.c
        oneDimArray/oneDimArray.h oneDimArray/oneDimArray.c
        testSet.c bool_array_set/bool_array_set.h bool_array_set/bool_array_set.c)
