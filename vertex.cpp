#include "vertex.h"

vertex::vertex(int value, int desiredRootValue)
{
	data = value;
    vertexColor = eColors::White;
    myRootValue = desiredRootValue;
}

int vertex::getData() const
{
	return data;
}

int vertex::getNumOfEdges() const
{
	return (int)vertexEdges.size();
}

set<vertex*>& vertex::getEdgesList()
{
	return vertexEdges;
}

void vertex::addNeighbor(vertex* neighborVertex)
{
    vertexEdges.insert(neighborVertex);
}

bool vertex::removeNeighbor(vertex* neighborVertex)
{
    for (auto currentVertex = vertexEdges.begin(); currentVertex != vertexEdges.end(); currentVertex++)
    {
        if (*currentVertex == neighborVertex)
        {
            vertexEdges.erase(currentVertex);
            return true;
        }
    }
    return false;
}