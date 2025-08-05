#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <string>


class taskManager{

    private:
    std::vector<std::string> tasks;
    std::map<std::string, std::function<void(void)>> commandMap;
    bool running;
    
    void taskadd();
    void tasklist();
    void taskremove();
    void Appexit();
    void showhelp();
    
    public:
    taskManager();
    void run();
};

#endif // TASKMANAGER_H