// trimmer.h

#ifndef TRIMMER_H
#define TRIMMER_H

#include <string>

class FileNotFoundError : public std::exception {
public:
    const char* what() const noexcept override {
        return "File not found.";
    }
};

class EmptyFileError : public std::exception {
public:
    const char* what() const noexcept override {
        return "File is empty.";
    }
};

class DirectoryNotFoundError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Directory not found.";
    }
};

void process_arguments(int argc, char* argv[], std::string& input, std::string& output);
void modify_text_file(const std::string& input_path, const std::string& output_path);

#endif // TRIMMER_H
