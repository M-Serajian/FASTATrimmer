#include <gtest/gtest.h>
#include "argument_parser.h"
#include "trimmer.h"
#include <iostream>
#include <unistd.h>  // Include for getcwd
#include <fstream>

// ANSI escape code for blue text
#define ANSI_BLUE "\033[34m"

// ANSI escape code to reset text color
#define ANSI_RESET "\033[0m"

class TrimmerTest : public ::testing::Test {
protected:
    void callProcessArguments(int argc, const char* argv[], std::string& input_file, std::string& output_dir) {
        try {
            process_arguments(argc, const_cast<char**>(argv), input_file, output_dir);
        } catch (const std::exception& e) {
            exception_message = e.what();
        }
    }

    void SetUp() override {
        // Prepare a temporary input file
        const std::string input_content = "This is a sample text file.";
        input_path = "test_input.txt";
        std::ofstream input_file(input_path);
        input_file << input_content;
        input_file.close();
    }

    void TearDown() override {
        // Clean up: Remove temporary files
        std::remove(input_path.c_str());
        std::remove(output_path.c_str());
    }

    std::string exception_message;
    std::string input_path;
    std::string output_path;
};

TEST_F(TrimmerTest, CorrectArguments) {
    int argc = 5;
    const char* argv[] = {"program_name", "-i", "/absolute/path/to/your/project/data/genomes/1773.1547.fna", "-o", "."};

    std::string input_file, output_dir;
    callProcessArguments(argc, argv, input_file, output_dir);

    // Update the expectation for exception_message
    EXPECT_EQ("Error: File '/absolute/path/to/your/project/data/genomes/1773.1547.fna' not found.", exception_message);

    EXPECT_EQ(".", output_dir);
}

TEST_F(TrimmerTest, MissingInputOption) {
    int argc = 3;
    const char* argv[] = {"program_name", "-o", "output_directory"};

    std::string input_file, output_dir;
    callProcessArguments(argc, argv, input_file, output_dir);

    EXPECT_NE("", exception_message);
    EXPECT_EQ("Usage: program_name -i <input_directory> -o <output_directory>", exception_message);
}

TEST_F(TrimmerTest, MissingOutputOption) {
    int argc = 3;
    const char* argv[] = {"program_name", "-i", "/absolute/path/to/your/project/data/genomes/1773.1547.fna"};

    std::string input_file, output_dir;
    callProcessArguments(argc, argv, input_file, output_dir);

    EXPECT_NE("", exception_message);
    EXPECT_EQ("Usage: program_name -i <input_directory> -o <output_directory>", exception_message);
}

TEST_F(TrimmerTest, ModifyTextFile) {
    // Define file paths
    const std::string input_file_path = "/home/m.serajian/projects/FASTATrimmer/data/genomes/1773.1547.fna";
    const std::string output_directory = "/home/m.serajian/projects/FASTATrimmer/data/genomes/ModifyTextFile_output/";
   
    // Check if the input file exists
    std::ifstream input_check(input_file_path);
    ASSERT_TRUE(input_check.is_open()) << "Failed to open input file: " << input_file_path;
    input_check.close();

    // Call the modify_text_file function
    modify_text_file(input_file_path, output_directory);

    // Verify the output file content
    std::string output_path = output_directory + "1773.1547.fna";
    std::ifstream output_file(output_path);
    std::ifstream correct_file("/home/m.serajian/projects/FASTATrimmer/data/genomes/correct_1773.1547.fna");

    // Check if both files are open
    ASSERT_TRUE(output_file.is_open()) << "Failed to open output file: " << output_path;
    ASSERT_TRUE(correct_file.is_open()) << "Failed to open correct file: /absolute/path/to/your/project/data/genomes/correct_1773.1547.fna";

    // Read content of both files
    std::stringstream output_buffer, correct_buffer;
    output_buffer << output_file.rdbuf();
    correct_buffer << correct_file.rdbuf();

    // Compare the content
    EXPECT_EQ(output_buffer.str(), correct_buffer.str())
        << "Output content does not match the correct content.";

    // Close the files
    output_file.close();
    correct_file.close();
}

int main(int argc, char** argv) {
    std::cout << ANSI_BLUE << "Running tests for argument_parser.cpp using Google Test..." << ANSI_RESET << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();

    std::cout << ANSI_BLUE << "Tests for argument_parser.cpp using Google Test are finished." << ANSI_RESET << std::endl;

    return result;
}
