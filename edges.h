#ifndef SUPER_GRAPH_ALGORITHM_ASSIGNMENT_EDGES_H
#define SUPER_GRAPH_ALGORITHM_ASSIGNMENT_EDGES_H

#include "vertex.h"

class edges
{
public:
	bool isVisited;
	vertex* vertexDestination;

	edges(vertex* newVertex) { vertexDestination = newVertex; isVisited = false; };
};

#endif // SUPER_GRAPH_ALGORITHM_ASSIGNMENT_EDGES_H