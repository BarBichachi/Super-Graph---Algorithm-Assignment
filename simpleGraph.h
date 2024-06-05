#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H

#include "vertex.h"
#include <list>
#include <iostream>
using namespace std;

class simpleGraph{
private:
    int numOfVertices;
    int numOfEdges;
    list<vertex*> verticesList;

public:
    void makeEmptyGraph(int numOfVertices);
    void addVertex(vertex& vertexToAdd);
    vertex* findVertexByValue(int value);
    void makeWhiteGraph();
    static bool isAdjacent(vertex& vertexSource, vertex& vertexDestination);
    bool addEdgeUI(int vertexSourceValue, int vertexDestinationValue);
    bool addEdge(vertex& vertexSource, vertex& vertexDestination);
    bool removeEdge(vertex& vertexSource, vertex& vertexDestination);
    void DFSEndList(list<int>& endList);
    void visitVertexAddToList(vertex &currentVertex, list<int>& endList);
    void DFSWithEndListToSuperGraph(list<int>& listWorkingOrder, simpleGraph& superGraph);
    void visitVertexAddToSuperGraph(vertex& fatherVertex, vertex& RootVertexInSuper, simpleGraph& superGraph);
    void makeTransposeGraphFrom(simpleGraph* sourceGraph);
    simpleGraph& makeSuperGraphKSAlgo();
    void printGraph();
    simpleGraph() = default;
    ~simpleGraph();
};


#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_SIMPLE_GRAPH_H
