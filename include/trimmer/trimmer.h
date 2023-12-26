// trimmer.h
#pragma once

#include <stdexcept>
#include <string>

class FileNotFoundError : public std::runtime_error
{
public:
    FileNotFoundError(const std::string &msg);
};

class EmptyFileError : public std::runtime_error
{
public:
    EmptyFileError(const std::string &msg);
};

class DirectoryNotFoundError : public std::runtime_error
{
public:
    DirectoryNotFoundError(const std::string &msg);
};

void modify_text_file(const std::string &input_path, const std::string &output_path);
