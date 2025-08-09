#include "TaskManager.h"
#include <iostream>
#include <limits>

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
        std::cout<<"> "; std::getline(std::cin, input);
        
        if(input.empty()) continue;
        auto it = commandMap.find(input);
        if(it != commandMap.end()){
            it->second();
        }else{
            std::cout<<"Unknown command, Type: 'help' to see commends"<<std::endl;
        }
    }
}

bool taskManager::checkTask(const std::string& element){
    return taskList.exist(element);
}

// Prompts the user to enter a new task and adds it to the task list.
void taskManager::taskadd(){
    std::string newTask;
    int position;
    
    std::cout<<"Enter the task you want to add: "; 
    std::getline(std::cin, newTask);
    
    if(newTask.empty()){
        std::cout<<"Unvalid attempt"<<std::endl;
        return (taskadd());
    }
    
    std::cout<<"Enter the order you want to insert: "; 
    if( !(std::cin >> position) ) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Unvalid attempt"<<std::endl;
        return taskadd();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    taskList.add(newTask,position);
    if(checkTask(newTask)){
        std::cout<<"Task added succesfully"<<std::endl;
    }else{
        std::cout<<"Something went wrong, try again"<<std::endl;
        return taskadd();
    }
}

// Displays all current tasks in the list with numbered order. 
void taskManager::tasklist(){
    taskList.display();
}
// Prompts the user to enter the number of a task to remove it from the list.
void taskManager::taskremove(){
    if(!taskList.isEmpty()){
        std::cerr<<"List is empty.\n";
    }
    else{
        int choice;
        std::cout<<"Enter the task order you want to delete: "; 
        std::cin>>choice;
        std::cin.ignore();
        if(!taskList.remove(choice)){
            std::cout<<"Unvalid attempt"<<std::endl;
            return taskremove();
        }
        std::cout<<"Task removed succesfully"<<std::endl;
    }
    
}
// Exits the task manager application.                                 
void taskManager::Appexit(){
    std::cout<<"Goodbye!"<<std::endl;
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