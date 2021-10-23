cmake_minimum_required(VERSION 3.10)

# set the project name
project(chrl4test VERSION 1.0)

add_executable(chrl4test ut_chrl4.cc ../chrl4-1.cc)
target_link_libraries(chrl4test gtest_main)

include(GoogleTest)
gtest_discover_tests(chrl4test)

set_tests_properties(${noArgsTests} PROPERTIES TIMEOUT 10)