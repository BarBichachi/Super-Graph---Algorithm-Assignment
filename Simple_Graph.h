#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H

#include <list>
#include "tree.h"
#include <iostream>

using namespace std;

class Simple_Graph{
private:
    int vertices;//n
    int edges;//m
    list<list<int> > adjacentList;

public:
    void makeEmptyGraph(int n);
    bool isAdjacent(int u,int v);
    list<int> getAdjList(int u);
    void addEdge(int u,int v);
    bool removeEdge(int u,int v);
    list<int> DFSEndList();
    list<tree> DFSTrees(list<int> listWorkingOrder);
    Simple_Graph makeTransposeGraph();

};


#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
