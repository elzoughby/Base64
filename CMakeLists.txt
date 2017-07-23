cmake_minimum_required(VERSION 3.7)
project(Base64)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c base64.h base64.c)
add_executable(Base64 ${SOURCE_FILES})