#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H

#include <list>
#include <iostream>
#include "tree.h"
#include "vertex.h"
#include "edges.h"

using namespace std;

class simpleGraph{
private:
    int numOfVertices; // n
    int numOfEdges; // m
    list<vertex> verticesList;

public:
    void makeEmptyGraph(int numOfVertices);
    void addVertex(int i);
    void makeWhiteGraph();
    bool isAdjacent(int vertexSource,int vertexDestination);
    void addEdge(int vertexSourceValue, int vertexDestinationValue);
    bool removeEdge(int vertexSourceValue, int vertexDestinationValue);
    list<int> DFSEndList();
    void visitVertexAddToList(vertex &currentVertex, list<int>& endList);
    list<tree*> DFSTrees(list<int> listWorkingOrder, simpleGraph& superGraph);
    void visitVertexAddToTree(vertex& currentVertex, node& currentVertexNode, int rootValue, simpleGraph& superGraph);
    simpleGraph makeTransposeGraph(list<int> endList);
    list<int> stronglyConnectedComponents(list<tree*> DFSTrees);
    simpleGraph& makeSuperGraphKSAlgo();
    void printGraph();
};


#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
