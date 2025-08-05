#include "TaskManager.h"

taskManager::taskManager() : running(true)  {
    commandMap["add"]    = std::bind(&taskManager::taskadd, this);
    commandMap["list"]   = std::bind(&taskManager::tasklist, this);
    commandMap["remove"] = std::bind(&taskManager::taskremove, this);
    commandMap["exit"]   = std::bind(&taskManager::Appexit, this);
    commandMap["help"]   = std::bind(&taskManager::showhelp, this);
}
void taskManager::run(){
    // Menu 
    std::string input;
    std::cout<<"Welcome to Task Manager\n"<<std::endl;
    showhelp();
    while(running){
        std::cout<<">"; std::getline(std::cin, input);
        
        if(input.empty()) continue;
        auto it = commandMap.find(input);
        if(it != commandMap.end()){
            it->second();
        }else{
            std::cout<<"Unknown command, Type: 'help' to see commends"<<std::endl;
        }
    }
}


// Prompts the user to enter a new task and adds it to the task list.
void taskManager::taskadd(){
    std::cout<<"add task"<<std::endl;
}
// Displays all current tasks in the list with numbered order. 
void taskManager::tasklist(){
    std::cout<<"see list"<<std::endl;
}
// Prompts the user to enter the number of a task to remove it from the list.
void taskManager::taskremove(){
    std::cout<<"remove task"<<std::endl;
    
}
// Exits the task manager application.                                 
void taskManager::Appexit(){
    running = false;
}    
// Displays a list of available commands with brief descriptions.
void taskManager::showhelp(){
    std::cout<<"| Command  | Description                                                                |"<<std::endl;
    std::cout<<"| -------- | -------------------------------------------------------------------------- |"<<std::endl;
    std::cout<<"| `add`    | Prompts the user to enter a new task and adds it to the task list.         |"<<std::endl;
    std::cout<<"| `list`   | Displays all current tasks in the list with numbered order.                |"<<std::endl;
    std::cout<<"| `remove` | Prompts the user to enter the number of a task to remove it from the list. |"<<std::endl;
    std::cout<<"| `exit`   | Exits the task manager application.                                        |"<<std::endl;
    std::cout<<"| `help`   | Displays a list of available commands with brief descriptions.             |"<<std::endl;
}    









// task manager commend lines
/*
| Command  | Description                                                                |
| -------- | -------------------------------------------------------------------------- |
| `add`    | Prompts the user to enter a new task and adds it to the task list.         |
| `list`   | Displays all current tasks in the list with numbered order.                |
| `remove` | Prompts the user to enter the number of a task to remove it from the list. |
| `exit`   | Exits the task manager application.                                        |
| `help`   | Displays a list of available commands with brief descriptions.             |

*/