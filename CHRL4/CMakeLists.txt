cmake_minimum_required(VERSION 3.10)

# set the project name
project(CHRL4-1 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# copy files around
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test)

# add the executable
add_executable(CHRL4-1 chrl4-1.cc)

# Unit Test
enable_testing()
add_subdirectory(UT)