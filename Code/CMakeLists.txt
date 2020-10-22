cmake_minimum_required(VERSION 3.15.3)
project(Code C)

set(CMAKE_C_STANDARD 99)

add_executable(Code main.c validator_xml.h validator_xml.c)