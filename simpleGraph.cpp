#include "simpleGraph.h"

void simpleGraph::makeEmptyGraph(int numOfVertices)
{
    this->numOfVertices = numOfVertices;
    this->numOfEdges = 0;

    for (int i = 0; i < numOfVertices; i++)
    {
        vertex* currentVertex = new vertex(i + 1);
        verticesList.push_back((*currentVertex));
    }
}

bool simpleGraph::isAdjacent(int vertexSourceValue, int vertexDestinationValue)
{
    auto vertexSource = this->verticesList.begin();
    advance(vertexSource, vertexSourceValue - 1);

    list<vertex*> vertexSourceEdgesList = (*vertexSource).getEdgesList();

    for (auto vertex : vertexSourceEdgesList)
    {
        if (vertex->getData() == vertexDestinationValue)
        {
            return true;
        }
    }
    return false;
}

list<int> simpleGraph::getAdjacentList(int u)
{
    list<int> stam;
    return stam;
}

void simpleGraph::addEdge(int vertexSourceValue, int vertexDestinationValue)
{
    if (vertexDestinationValue > numOfVertices || vertexSourceValue > numOfVertices)
    {
        cout << "One of the vertices does not exist in the graph!" << endl;
    }
    else if (vertexSourceValue == vertexDestinationValue)
    {
        cout << "Can't make an edge from the source vertex to itself!" << endl;
    }
    else
    {
        auto vertexSource = this->verticesList.begin();
        advance(vertexSource, vertexSourceValue - 1);

        auto vertexDestination = this->verticesList.begin();
        advance(vertexDestination, vertexDestinationValue - 1);

        (*vertexSource).addNeighbor(&(*vertexDestination));
        numOfEdges++;
    }
}

bool simpleGraph::removeEdge(int vertexSourceValue, int vertexDestinationValue)
{
    bool isRemoved = true;

    if (vertexDestinationValue > numOfVertices || vertexSourceValue > numOfVertices)
    {
        cout << "One of the vertices does not exist in the graph!" << endl;
        isRemoved = false;
    }
    else if (vertexSourceValue == vertexDestinationValue)
    {
        cout << "It's a simple graph, there can't be an edge from a vertex to itself!" << endl;
        isRemoved = false;
    }
    else
    {
        auto vertexSource = this->verticesList.begin();
        advance(vertexSource, vertexSourceValue - 1);

        auto vertexDestination = this->verticesList.begin();
        advance(vertexDestination, vertexDestinationValue - 1);

        isRemoved = (*vertexSource).removeNeighbor(&(*vertexDestination));

        if (isRemoved)
        {
            numOfEdges--;
        }
        else
        {
            cout << "This edge does not exist in the graph!" << endl;
            isRemoved = false;
        }
    }

    return isRemoved;
}

list<int> simpleGraph::DFSEndList()
{
    list<int> stam;
    return stam;
}

list<tree> simpleGraph::DFSTrees(list<int> listWorkingOrder)
{
    list<tree> stam;
    return stam;
}

simpleGraph simpleGraph::makeTransposeGraph()
{
    simpleGraph stam;
    return stam;
}