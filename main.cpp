#include <iostream>
#include <filesystem>
#include "src/app/processes/ProcessManagement.hpp"
#include "src/app/processes/Task.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    std::string directory;
    std::string action;

    std::cout << "Enter the direcctory path: " << std::endl;
    std::getline(std::cin, directory);

    std::cout << "Enter the action(encrypt/decrypt): " << std::endl;
    std::getline(std::cin, action);
    try
    {
        if (fs::exists(directory) && fs::is_directory(directory))
        {
            ProcessManagement processManagement;
            for (const auto &entry : fs::recursive_directory_iterator(directory)) // by default funciton goes directory directory by directory
            {
                if (entry.is_regular_file())
                {
                    std::string filePath = entry.path().string();
                    IO io(filePath);
                    std::fstream f_stream = std::move(io.getFileStream());

                    if (f_stream.is_open())
                    {
                        Action taskAction = (action == "encrypt" ? Action::ENCRYPT : Action::DECRYPT);
                        auto task = std::make_unique<Task>(std::move(f_stream), taskAction, filePath);
                        processManagement.submitToQueue(std::move(task));
                    }
                    else
                    {
                        std::cout << "unable to open file " << filePath;
                    }
                }
            }

            processManagement.executeTask();
        }
        else
        {
            std::cout << "Directory does not exist" << std::endl;
        }
    }
    catch (const fs::filesystem_error &ex)
    {
        std::cout << "filesystem error: " << ex.what() << std::endl;
    }
}