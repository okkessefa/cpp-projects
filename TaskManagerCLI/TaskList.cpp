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

// For those function get help from Linked List Notes
void taskList::add(const std::string& task){
    Node* newtask = new Node(task);
    newtask->next = head;
    head = newtask;
}
bool taskList::remove(int index){

}
void taskList::display() const {
    Node* temp = head;
    int taskOrder = 1;

    std::cout<<"---------------"<<std::endl;
    std::cout<<"The task List: "<<std::endl;
    std::cout<<"---------------"<<std::endl;
    while(temp != nullptr){
        std::cout<<taskOrder + ": "<<temp->next<<std::endl;
        temp = temp->next;
        taskOrder++;
    }
    std::cout<<"---------------"<<std::endl;
    std::cout<<"\n";

}
bool taskList::exist(const std::string& task) const{

}
int taskList::size() const{

}
