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
};
#endif