#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include <queue>
#include <memory>

class ProcessManagement
{

public:
    ProcessManagement();
    bool submitToQueue(std::unique_ptr<Task> task);
    void executeTask();

private:
    std::queue<std::unique_ptr<Task>> taskQueue;
};

#endif

// basic mallox
//  int *arr = (int*)malloc(3*sizeof(int));
// int* arr1 = arr;
// double free memory, memory leak

// unique pointer
// std::unique_ptr<int[]> arr = std::make_unique<int[]>(9);
// std::unique_ptr<int[]> arr1 = std::move(arr);
/*
no double memory free
ownership belong to only one pointer always thus no memory leak
scope limmited (auto memory free is goes out of scope)*/