cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR .)

set(SOURCES ${SOURCE_DIR}/main.cpp)

project(ultra-test VERSION 0.0.1 DESCRIPTION "Utra Test.")

add_executable(${PROJECT_NAME} ${SOURCES})
