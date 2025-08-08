#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <map>
#include <functional>
#include <string>
#include "TaskList.h"

class taskManager {
private:
    taskList taskList;
    std::map<std::string, std::function<void(void)>> commandMap;
    bool running;

    bool checkTask(const std::string&);
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
