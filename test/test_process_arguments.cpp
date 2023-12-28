#include <gtest/gtest.h>
#include "argument_parser.h"
#include "trimmer.h"
#include <iostream>

// ANSI escape code for blue text
#define ANSI_BLUE "\033[34m"

// ANSI escape code to reset text color
#define ANSI_RESET "\033[0m"

class ProcessArgumentsTest : public ::testing::Test {
protected:
    void callProcessArguments(int argc, char* argv[], std::string& input_file, std::string& output_dir) {
        try {
            process_arguments(argc, argv, input_file, output_dir);
        } catch (const std::exception& e) {
            exception_message = e.what();
        }
    }

    std::string exception_message;
};

TEST_F(ProcessArgumentsTest, CorrectArguments) {
    int argc = 5;
    char* argv[] = {"program_name", "-i", "input_file.txt", "-o", "."};

    std::string input_file, output_dir;
    callProcessArguments(argc, argv, input_file, output_dir);

    EXPECT_EQ("", exception_message);
    EXPECT_EQ("input_file.txt", input_file);
    EXPECT_EQ(".", output_dir);

}

TEST_F(ProcessArgumentsTest, MissingInputOption) {
    int argc = 3;
    char* argv[] = {"program_name", "-o", "output_directory"};

    std::string input_file, output_dir;
    callProcessArguments(argc, argv, input_file, output_dir);

    EXPECT_NE("", exception_message);
    EXPECT_EQ("Usage: program_name -i <input_directory> -o <output_directory>", exception_message);
}

TEST_F(ProcessArgumentsTest, MissingOutputOption) {
    int argc = 3;
    char* argv[] = {"program_name", "-i", "input_file.txt"};

    std::string input_file, output_dir;
    callProcessArguments(argc, argv, input_file, output_dir);

    EXPECT_NE("", exception_message);
    EXPECT_EQ("Usage: program_name -i <input_directory> -o <output_directory>", exception_message);

}

int main(int argc, char** argv) {
    std::cout << ANSI_BLUE << "Running tests for argument_parser.cpp using Google Test..." << ANSI_RESET << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();

    std::cout << ANSI_BLUE << "Tests for argument_parser.cpp using Google Test are finished." << ANSI_RESET << std::endl;

    return result;
}
