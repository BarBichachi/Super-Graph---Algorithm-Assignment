#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_NODE_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_NODE_H

#include <iostream>
#include <list>

using namespace std;

class node {
private:
    int data;
    list<node*> children;

public:
    node(int value);
    ~node();
    int getData() const;
    int getNumOfChildren() const;
    list<node*> getChildrenList();
    void addChild(node* child);
    bool removeChild(node* child);
};

#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_NODE_H