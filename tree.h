#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_TREE_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_TREE_H

#include <iostream>
#include <list>
#include "node.h"

using namespace std;

class tree {
private:
    node* root;

public:
    tree();
    ~tree();
    node* getRoot();
    void setRoot(node* node);
    bool isTreeEmpty();
};


#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_TREE_H
