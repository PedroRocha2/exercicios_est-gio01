cmake_minimum_required(VERSION 3.22)

project(ListChainedExercise VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)

set(EXECUTABLE_NAME Executable)

file(GLOB_RECURSE EXE_SOURCES "${CMAKE_SOURCE_DIR}/sources/*.cpp")
set(EXE_INCLUDES "${CMAKE_SOURCE_DIR}/headers")

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${EXE_INCLUDES})