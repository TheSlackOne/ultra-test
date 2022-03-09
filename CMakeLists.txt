cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR_1 exercise1)
set(SOURCE_DIR_2 exercise2)

set(TEST_SOURCES_1 tests.cpp)
set(TEST_SOURCES_2 tests.cpp)

project(ultra-test VERSION 1.0.0 DESCRIPTION "Ultra Test.")

add_executable("tests" ${TEST_SOURCES_1} ${TEST_SOURCES_2})

find_package(Boost 1.71 COMPONENTS unit_test_framework REQUIRED)

target_link_libraries("tests" ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
