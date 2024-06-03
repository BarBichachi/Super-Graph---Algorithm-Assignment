#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H

#include <list>
#include "colors.h"
#include "node.h"

using namespace std;

class vertex
{
private:
	int data;
    list<vertex*> vertexEdges;

public:
    eColors vertexColor;
    int myRootValue;

    vertex(int value, int desiredRootValue = -1);
    int getData();
    int getNumOfEdges();
    list<vertex*>& getEdgesList();
    void addNeighbor(vertex* neighborVertex);
    bool removeNeighbor(vertex* neighborVertex);
};

#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H