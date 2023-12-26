# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(FASTATrimmer)

set(CMAKE_CXX_STANDARD 17)

# Set the paths to include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include/trimmer
    ${CMAKE_SOURCE_DIR}/include/regex
)

# Create a bin directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add executable and specify source files
add_executable(FASTATrimmer 
    src/main.cpp 
    src/trimmer.cpp 
    src/argument_parser.cpp
)

# Alternatively, you can use target_include_directories:
# target_include_directories(FASTATrimmer PRIVATE ${CMAKE_SOURCE_DIR}/include/trimmer ${CMAKE_SOURCE_DIR}/include/regex)
