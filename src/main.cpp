// main.cpp
#include "argument_parser.h"
#include "trimmer.h"
#include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        std::string input_file, output_dir;
        process_arguments(argc, argv, input_file, output_dir);

        // Extract the base name from the input file path
        size_t last_slash_pos = input_file.find_last_of('/');
        std::string file_name = (last_slash_pos != std::string::npos) ? input_file.substr(last_slash_pos + 1) : input_file;
        std::cout << "Input File: " << file_name << std::endl;

        std::string output_file_directory = output_dir + '/' + file_name;
        std::cout << "Output File Directory: " << output_file_directory << std::endl;

        modify_text_file(input_file, output_file_directory);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
