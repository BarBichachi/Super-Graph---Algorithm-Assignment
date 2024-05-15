#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H

#include <list>
#include "tree.h"
#include "vertex.h"
#include <iostream>

using namespace std;

class simpleGraph{
private:
    int numOfVertices; //n
    int numOfEdges; //m
    list<vertex> verticesList;

public:
    void makeEmptyGraph(int numOfVertices);
    bool isAdjacent(int vertexSource,int vertexDestination);
    list<int> getAdjacentList(int u);
    void addEdge(int u,int v);
    bool removeEdge(int u,int v);
    list<int> DFSEndList();
    list<tree> DFSTrees(list<int> listWorkingOrder);
    simpleGraph makeTransposeGraph();

};


#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
