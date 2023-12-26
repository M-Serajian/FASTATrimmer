#include <iostream>
#include <filesystem> // Include the filesystem header
#include "trimmer/trimmer.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " input_file output_directory" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::string output = argv[2];

    try {
        std::string file_name = std::filesystem::path(input).filename();
        std::cout << file_name << std::endl;

        std::string output_file_directory = (std::filesystem::path(output) / file_name).string();
        std::cout << output_file_directory << std::endl;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
