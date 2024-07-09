#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "IO.hpp"

class ReadEnv
{
public:
    std::string getenv()
    {
        std::string env_path = ".env"; // direcly no need to "../../../."
        IO io(env_path);
        std::fstream f_stream = io.getFileStream(); // return filestream
        std::stringstream buffer;
        buffer << f_stream.rdbuf();         // want to open file in string stream to get data;
        std::string content = buffer.str(); // reads file
        return content;
    }
};