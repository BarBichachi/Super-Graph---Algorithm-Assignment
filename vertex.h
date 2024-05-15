#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H

#include <list>
#include "colors.h"

using namespace std;

class vertex
{
private:
	int data;
	list<vertex*> vertexEdges;

public:
    eColors vertexColor;

    vertex(int value);
    int getData();
    int getNumOfEdges();
    list<vertex*> getEdgesList();
    void addNeighbor(vertex* neighborVertex);
    bool removeNeighbor(vertex* neighborVertex);
};

#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H