#ifndef IO_HPP // ifnotdefined (get compiled only once)
#define IO_HPP

#include <fstream>
#include <string>
#include <iostream>

class IO
{
public:
    IO(const std::string &file_path);
    ~IO();
    std::fstream getFileStream();

    // stores the file
private:
    std::fstream file_stream;
};

#endif