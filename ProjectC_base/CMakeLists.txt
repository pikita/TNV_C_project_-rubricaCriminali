cmake_minimum_required(VERSION 3.22)
project(untitled2 C)

set(CMAKE_C_STANDARD 90)

add_executable(untitled2 main.c sort_libraries_define/sort_libraries_define.c sort_libraries_define/sort_libraries_define.h utilities/utilities.c utilities/utilities.h randomGeneration/randomGeneration.c randomGeneration/randomGeneration.h userInput/userInput.c userInput/userInput.h)
