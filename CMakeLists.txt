cmake_minimum_required(VERSION 3.10)

project(trimmer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find required packages (if any)

# Add include directory
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Set output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Create executable
add_executable(trimmer ${SOURCES})
