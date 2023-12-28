cmake_minimum_required(VERSION 3.10)
project(FASTATrimmer)

# Set the minimum C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

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

# Set the output directory for both executables to bin directory
set_target_properties(FASTATrimmer FASTATrimmerTests PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
