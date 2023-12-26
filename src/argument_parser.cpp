// argument_parser.cpp
#include "argument_parser.h"
#include "trimmer.h" // Include trimmer header for exceptions
#include <iostream>
#include <fstream>
#include <filesystem>

void process_arguments(int argc, char *argv[], std::string &input_file, std::string &output_dir)
{
    if (argc != 5 || std::string(argv[1]) != "-i" || std::string(argv[3]) != "-o")
    {
        throw std::invalid_argument("Usage: " + std::string(argv[0]) + " -i <input_directory> -o <output_directory>");
    }

    input_file = argv[2];
    output_dir = argv[4];

    // Check if the input file exists using C++17 filesystem
    if (!std::filesystem::exists(input_file))
    {
        throw FileNotFoundError("Error: File '" + input_file + "' not found.");
    }

    // Check if the input file is empty
    std::ifstream input_file_stream(input_file);
    if (input_file_stream.peek() == std::ifstream::traits_type::eof())
    {
        throw EmptyFileError("Error: File '" + input_file + "' is empty.");
    }

    // Check if the output directory exists
    if (!std::filesystem::exists(output_dir))
    {
        throw DirectoryNotFoundError("Error: Directory '" + output_dir + "' not found.");
    }
}
