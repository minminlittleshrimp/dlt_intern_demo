cmake_minimum_required(VERSION 3.10)

project(leak)

# Flag for ASAN enable
SET(CMAKE_C_FLAGS  "-fsanitize=address -fsanitize=leak ${CMAKE_C_FLAGS}")
SET(CMAKE_CXX_FLAGS  "-fsanitize=address -fsanitize=leak ${CMAKE_CXX_FLAGS}")

add_executable(leak leak.c)


