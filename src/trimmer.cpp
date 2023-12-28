#include "trimmer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

FileNotFoundError::FileNotFoundError(const std::string &msg) : std::runtime_error(msg) {}
EmptyFileError::EmptyFileError(const std::string &msg) : std::runtime_error(msg) {}
DirectoryNotFoundError::DirectoryNotFoundError(const std::string &msg) : std::runtime_error(msg) {}


void modify_text_file(const std::string &input_path, const std::string &output_directory) {
    // Read content from the input file
    std::ifstream input_file(input_path);
    if (!input_file.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string content = buffer.str();

    // Find the index of the last alphabetic character
    size_t last_letter_index = content.find_last_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (last_letter_index != std::string::npos) {
        // Erase all characters after the last alphabetic character
        content.erase(last_letter_index + 1);
    }

    // Add a single empty line at the end
    content += "\n";

    // Create the output directory if it doesn't exist
    std::filesystem::create_directories(output_directory);

    // Extract the filename from the input path
    std::filesystem::path input_file_path_obj(input_path);
    std::string output_file_name = input_file_path_obj.filename();

    // Create the output path by concatenating the output directory and the filename
    std::string output_path = output_directory + output_file_name;

    // Write modified content to the output file
    std::ofstream output_file(output_path);
    if (!output_file.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }
    output_file << content;
}
