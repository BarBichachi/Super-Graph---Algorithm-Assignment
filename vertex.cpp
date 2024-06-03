#include "vertex.h"

vertex::vertex(int value, int desiredRootValue)
{
	data = value;
    vertexColor = eColors::White;
    myRootValue = desiredRootValue;
}

int vertex::getData()
{
	return data;
}

int vertex::getNumOfEdges()
{
	return vertexEdges.size();
}

list<vertex*>& vertex::getEdgesList()
{
	return vertexEdges;
}

void vertex::addNeighbor(vertex* neighborVertex)
{
    vertexEdges.push_back(neighborVertex);
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