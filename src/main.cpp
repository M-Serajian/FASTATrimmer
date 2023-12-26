// main.cpp

#include "trimmer.h"

int main(int argc, char* argv[]) {
    try {
        std::string input, output;
        process_arguments(argc, argv, input, output);

        // Extract the base name from the input file path
        std::string file_name = std::filesystem::path(input).filename();
        std::cout << file_name << std::endl;

        std::string output_file_directory = (std::filesystem::path(output) / file_name).string();
        std::cout << output_file_directory << std::endl;

        modify_text_file(input, output_file_directory);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
