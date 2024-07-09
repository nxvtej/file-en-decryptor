// own data type to push data in queue

#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../fileHandling/IO.hpp"

enum class Action
{
    ENCRYPT,
    DECRYPT
};

struct Task
{
    std::string filePath;
    std::fstream f_stream;
    Action action;

    // for task defining here unlike IO.hpp here only using hpp file to
    // do complete task
    // movinf owndership here // && is temp buffer thus it will be moved without copy
    Task(std::fstream &&stream, Action act, std::string filePath) : f_stream(std::move(stream)), action(act), filePath(filePath) {}

    // instead of directly passing task to queue
    // serialization the task to ostringstream
    std::string toString()
    {
        std::ostringstream oss;
        oss << filePath << "," << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
        // example.txt ENCRYPT f_stream
        // then convert this into stream of string as
        // "example.txt,ENCRYPT"
        return oss.str();
    }

    // deserialize the task
    static Task fromString(const std::string &taskData)
    {
        std::istringstream iss(taskData);
        std::string filePath;
        std::string actionStr;

        // "," not this , created error as it was stirng
        if (std::getline(iss, filePath, ',') && std::getline(iss, actionStr))
        {
            // getting from string stream
            Action action = (actionStr == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);
            IO io(filePath);
            // this removes
            std::fstream f_stream = std::move(io.getFileStream()); // not just referecnce actual

            if (f_stream.is_open())
            {
                return Task(std::move(f_stream), action, filePath);
            }
            else
            {
                throw std::runtime_error("Failed to open file" + filePath);
            }
        }
        else
        {
            throw std::runtime_error("Invalid task format data");
        }
    }
};
#endif