cmake_minimum_required(VERSION 4.0)
project(afl_2_demo C)

set(CMAKE_C_STANDARD 23)

add_executable(afl_2_demo main.c
        perms.c
        perms.h)
