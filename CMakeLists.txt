cmake_minimum_required(VERSION 3.10)
project(FASTATrimmer)

# Set C++ standard and compilation flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Specify the source files
set(SOURCE_FILES
    src/main.cpp
    src/trimmer.cpp
)

# Specify the include directories
include_directories(include)

# Create the executable and link against filesystem library
add_executable(FASTATrimmer ${SOURCE_FILES})
target_link_libraries(FASTATrimmer stdc++fs)
