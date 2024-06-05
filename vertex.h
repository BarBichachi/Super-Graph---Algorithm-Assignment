#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H

#include <set>
#include "colors.h"
#include <list>

using namespace std;

class vertex
{
private:
	int data;
    list<vertex*> vertexEdges;

public:
    eColors vertexColor;
    vertex* myRootVertex;

    vertex(int value, vertex* myRootVertex = nullptr);
    vertex(vertex& copy);
    int getData() const;
    int getNumOfEdges() const;
    list<vertex*>& getEdgesList();
    void addNeighbor(vertex* neighborVertex);
    bool removeNeighbor(vertex* neighborVertex);
};

#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H