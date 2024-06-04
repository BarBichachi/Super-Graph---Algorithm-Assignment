#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H

#include <set>
#include "colors.h"
#include "node.h"

using namespace std;

class vertex
{
private:
	int data;
    set<vertex*> vertexEdges;

public:
    eColors vertexColor;
    int myRootValue;

    explicit vertex(int value, int desiredRootValue = -1);
    int getData() const;
    int getNumOfEdges() const;
    set<vertex*>& getEdgesList();
    void addNeighbor(vertex* neighborVertex);
    bool removeNeighbor(vertex* neighborVertex);
};

#endif //SUPER_GRAPH_ALGORITHM_ASSIGNMENT_VERTEX_H