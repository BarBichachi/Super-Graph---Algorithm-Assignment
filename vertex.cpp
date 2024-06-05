#include "vertex.h"

vertex::vertex(int value, vertex* myRootVertex)
{
	data = value;
    vertexColor = eColors::White;
    myRootVertex = myRootVertex;
}

vertex:: vertex(vertex& copy)
{
    this->data = copy.data;
    this->vertexColor = eColors::White;
    this->myRootVertex = copy.myRootVertex;
}

int vertex::getData() const
{
	return data;
}

int vertex::getNumOfEdges() const
{
	return (int)vertexEdges.size();
}

list<vertex*>& vertex::getEdgesList()
{
	return vertexEdges;
}

void vertex::addNeighbor(vertex* neighborVertex)
{
    vertexEdges.push_back(neighborVertex);
}

bool vertex:: removeNeighbor(vertex* neighborVertex)
{
    auto it = std::find(vertexEdges.begin(), vertexEdges.end(), neighborVertex);

    if (it != vertexEdges.end())
    {
        vertexEdges.erase(it);
        return true;
    }

    return false;
}