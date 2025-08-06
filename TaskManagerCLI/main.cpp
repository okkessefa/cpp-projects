#include "TaskManager.h"

int main()
{
    taskManager taskapp;
    taskapp.run();

    return 0;
}
// try this to compile the code
// as much as i experienced after making any changes in TaskManager.cpp file and want to 
// run the program you have to follow this order
//g++ -std=c++17 -g -o taskManagerCLI.exe main.cpp TaskManager.cpp
// then taskManagerCLI.exe 