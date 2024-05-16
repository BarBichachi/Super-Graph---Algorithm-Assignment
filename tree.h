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
    tree(node* root) { this->root = root; };
    ~tree() { delete root;};
    node* getRoot() { return root; };
    bool isTreeEmpty() { return root == nullptr; };
};


#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_TREE_H
