#ifndef NODE_H
#define NODE_H

#include <string>

struct Node{
    std::string descripton;
    Node* next;

    Node(const std::string& desc) : descripton(desc), next(nullptr) {}
};

#endif 