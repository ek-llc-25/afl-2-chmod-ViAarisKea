cmake_minimum_required(VERSION 4.0)
project(afl_2-chmod-ViAarisKea C)

set(CMAKE_C_STANDARD 23)

add_executable(afl_2-chmod-ViAarisKea main.c
        perms.c)
