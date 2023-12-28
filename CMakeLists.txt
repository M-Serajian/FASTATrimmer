cmake_minimum_required(VERSION 3.10)
project(FASTATrimmer)

# Set the minimum C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Create a bin directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add library for source files
add_library(FASTATrimmerLib
    src/trimmer.cpp 
    src/argument_parser.cpp
)

# Explicitly specify the path to the header files
target_include_directories(FASTATrimmerLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/trimmer
    ${CMAKE_CURRENT_SOURCE_DIR}/include/regex
)

# Add executable and link to the library
add_executable(FASTATrimmer 
    src/main.cpp 
)

target_link_libraries(FASTATrimmer PRIVATE FASTATrimmerLib)

# Include Google Test as a submodule
add_subdirectory(googletest)

# Enable CTest for running tests
enable_testing()

# Add a test for your test executable
add_executable(FASTATrimmerTests
    test/test_process_arguments.cpp
)

# Link the test executable with Google Test and the library
target_link_libraries(FASTATrimmerTests PRIVATE gtest gtest_main FASTATrimmerLib)

# Add a test for your test executable
add_test(NAME MyTest COMMAND FASTATrimmerTests)
