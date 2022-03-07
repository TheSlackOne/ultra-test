cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR_1 exercise1)
set(SOURCE_DIR_2 exercise2)

set(SOURCES_1 ${SOURCE_DIR_1}/exercise1.cpp)
set(SOURCES_2 ${SOURCE_DIR_2}/exercise2.cpp)

project(ultra-test VERSION 0.0.1 DESCRIPTION "Utra Test.")

add_executable("exercise1" ${SOURCES_1})
#add_executable("exercise2" ${SOURCES_2})
