#include "ProcessManagement.hpp"
#include <iostream>
#include <cstring>
// #include <sys/wait.h>
#include <../encryptDecrypt/src/app/encrypt/Cryption.hpp>

ProcessManagement::ProcessManagement() {}

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task)
{
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTask()
{
    while (!taskQueue.empty())
    {
        std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
        taskQueue.pop();

        std::cout << "executing task" << taskToExecute->toString() << std::endl;
        executeCryption(taskToExecute->toString());
    }
}