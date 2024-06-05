#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H

#include <list>
#include <iostream>
#include "vertex.h"

using namespace std;

class simpleGraph{
private:
    int numOfVertices; // n
    int numOfEdges; // m
    list<vertex*> verticesList;

public:
    void makeEmptyGraph(int numOfVertices);
    void addVertex(vertex& vertexToAdd);
    void makeWhiteGraph();
    static bool isAdjacent(vertex& vertexSource, vertex& vertexDestination);
    void addEdgeUI(int vertexSourceValue, int vertexDestinationValue);
    bool addEdge(vertex& vertexSource, vertex& vertexDestination);
    bool removeEdge(vertex& vertexSource, vertex& vertexDestination);
    list<vertex*> DFSEndList(list<vertex*>& endList);
    list<vertex*> reverseListInMyGraph(list<vertex*>&endList);
    void visitVertexAddToList(vertex &currentVertex, list<vertex*>& endList);
    void DFSWithEndListToSuperGraph(list<vertex*>& listWorkingOrder, simpleGraph& superGraph);
    void visitVertexAddToSuperGraph(list<vertex*>& listNeighbor, vertex& RootVertex, vertex& RootVertexInSuper, simpleGraph& superGraph);
    void makeTransposeGraphFrom(simpleGraph* sourceGraph);
    simpleGraph& makeSuperGraphKSAlgo();
    void printGraph();
};


#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
