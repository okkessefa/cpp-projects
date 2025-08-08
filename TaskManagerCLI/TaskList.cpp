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
void taskList::add(const std::string& task, const int& position){
    Node* newtask = new Node(task);
    if(position == 1){
    newtask->next = head;
    head = newtask;
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

bool taskList::remove(int index){
    if(head == nullptr){
        std::cerr<<"Delete Error: List is empty.\n";
        return;
    }
    // deleting head task
    if(index == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    for(int i = 1; i < index -1 && temp != nullptr; ++i){
        temp = temp->next;
    }
    if(head == nullptr || temp->next == nullptr){
        std::cerr<<"Delete Error: List is empty.\n";
        return;
    }
    Node* taskToDelete = temp->next;
    temp->next = taskToDelete->next;
    delete taskToDelete;
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
