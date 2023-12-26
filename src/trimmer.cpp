// trimmer.cpp
#include "trimmer.h"
#include <iostream>
#include <fstream>
#include <sstream>

FileNotFoundError::FileNotFoundError(const std::string &msg) : std::runtime_error(msg) {}
EmptyFileError::EmptyFileError(const std::string &msg) : std::runtime_error(msg) {}
DirectoryNotFoundError::DirectoryNotFoundError(const std::string &msg) : std::runtime_error(msg) {}


void modify_text_file(const std::string &input_path, const std::string &output_path)
{
    std::ifstream input_file(input_path);
    if (!input_file.is_open())
    {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string content = buffer.str();

    size_t last_letter_index = std::string::npos;
    for (size_t i = content.size(); i > 0; --i)
    {
        if (std::isalpha(content[i - 1]))
        {
            last_letter_index = i - 1;
            break;
        }
    }

    std::string modified_content;
    if (last_letter_index != std::string::npos)
    {
        modified_content = content.substr(0, last_letter_index + 1);
        modified_content.erase(modified_content.find_last_not_of("\n") + 1) += "\n";
    }
    else
    {
        modified_content = content + "\n";
    }

    std::ofstream output_file(output_path);
    if (!output_file.is_open())
    {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    output_file << modified_content;
}
