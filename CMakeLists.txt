cmake_minimum_required(VERSION 3.2)

project(cll)
add_library(cll SHARED cll.c cll.h)
add_executable(cll_test cll.c)
