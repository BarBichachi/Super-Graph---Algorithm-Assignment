#include "vertex.h"

vertex::vertex(int value)
{
	data = value;
    vertexColor = eColors::White;
    myRootVertex = nullptr;
}

vertex:: vertex(vertex& copy)
{
    this->data = copy.data;
    this->vertexColor = eColors::White;
    this->myRootVertex = copy.myRootVertex;
}

vertex:: ~vertex()
{
    vertexEdges.clear();
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

bool vertex::removeNeighbor(vertex* neighborVertex)
{
    for (auto itNeighborVertex = vertexEdges.begin(); itNeighborVertex != vertexEdges.end(); ++itNeighborVertex)
    {
        if (*itNeighborVertex == neighborVertex)
        {
            vertexEdges.erase(itNeighborVertex);
            return true;
        }
    }
    return false;
}