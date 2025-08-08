#ifndef TASKLIST_H
#define TASKLIST_H

#include "Node.h"

class taskList{
    private:
    Node* head;


    public:
    taskList();
    ~taskList();
    
    void add(const std::string& task, const int& position);
    bool remove(int index);
    void display() const;
    bool exist(const std::string& task) const;
    int size() const;

};

#endif 