#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_NODE_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_NODE_H

#include <iostream>
#include <list>

using namespace std;

class node {
private:
    int data;
    list<node*> childrens;

public:
    node(int value);
    ~node();
    int getData();
    int getNumOfChildrens();
    list<node*> getChildrensList();
    void addChild(node* child);
    bool removeChild(node* child);
};

#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_NODE_H