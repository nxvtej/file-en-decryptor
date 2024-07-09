#include <iostream>
#include "IO.hpp"
#include <fstream>

// using namespace std;

IO::IO(const std::string &file_path) // take from .hpp file and apply constructor
{
    file_stream.open(file_path, std::ios::in | std::ios::out | std::ios::binary); // all possible methods for file

    if (!file_stream.is_open())
    {
        std::cout << "File not found" << file_path << std::endl;
    }
}