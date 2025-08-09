#include "TaskList.h"
#include <iostream>

// folllow the taskmnager pattern to build new file

taskList::taskList() : head(nullptr) {}

taskList::~taskList() {
    while(head){
        Node* temp = head;
        temp = temp->next;
        delete temp;
    }
}

// Adding particular Node task into selected order
void taskList::add(const std::string& task, const int& position){
    if(position < 1){
        std::cerr<<"Position must be equal or bigger than 0\n";
    }

    Node* newtask = new Node(task);
    newtask->descripton = task;

    if(head == nullptr || position == 1){
        newtask->next = head;
        head = newtask;
        return;
    }

    Node* temp = head;
    for(int i = 1; i < position -1 && temp != nullptr; ++i){
        temp = temp->next;
    }
    if(temp == nullptr){
        std::cerr<<"Position out of bounds.\n";
        delete newtask;
        return;
    }
    newtask->next = temp->next;
    temp->next = newtask;
}

// Removing particular Node task from selected order
bool taskList::remove(int index){
    // change it with isEmpty function
    if(!isEmpty()){
        return false;
    }
    // deleting head task
    if(index == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    Node* temp = head;
    for(int i = 1; i < index -1 && temp != nullptr; ++i){
        temp = temp->next;
    }
    if(head == nullptr || temp->next == nullptr){
        // ismepty function
        std::cerr<<"List is empty.\n";
        return false;
    }
    Node* taskToDelete = temp->next;
    temp->next = taskToDelete->next;
    delete taskToDelete;
    return true;
}
// Displaying all Node tasks
void taskList::display() const {
    Node* display_temp = head;
    int taskOrder = 1;
    if(!isEmpty()){
        std::cout<<"List is empty"<<std::endl;
    }
    else{
        std::cout<<"---------------"<<std::endl;
        std::cout<<"The task List: "<<std::endl;
        std::cout<<"---------------"<<std::endl;
        while(display_temp != nullptr){
            std::cout<<taskOrder <<": ";
            std::cout<<display_temp->descripton<<std::endl;
            display_temp = display_temp->next;
            taskOrder++;
        }
        std::cout<<"---------------"<<std::endl;
    }
}

bool taskList::exist(const std::string& task) const{

    Node* check_exist = head;
    for(int i = 0; i<size(); i++){
        if(check_exist->descripton == task){
            return true;
        }
        i++;
        check_exist = check_exist->next;
    }
    return false;
}
int taskList::size() const{

    Node* temp = head;
    int taskSize = 0;
    while(temp != nullptr){
        taskSize++;
        temp = temp->next;
    }
    return taskSize;
}

// If list is empty thisv function return false otherwise it returns true
bool taskList::isEmpty() const {
    if(head == nullptr){
        return false;
    }
    return true;
}
