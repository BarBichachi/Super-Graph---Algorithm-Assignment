#include "simpleGraph.h"

void simpleGraph::makeEmptyGraph(int desiredNumOfVertices)
{
	this->numOfVertices = 0;
	this->numOfEdges = 0;

	for (int i = 1; i <= desiredNumOfVertices; i++)
	{
        auto* currentVertex = new vertex(i);
        verticesList.push_back((currentVertex));
        this->numOfVertices++;
	}
}

void simpleGraph::addVertex(vertex& vertexToAdd)
{
    verticesList.push_back(&vertexToAdd);
    (this->numOfVertices)++;
}

vertex* simpleGraph:: findVertexByValue(int value)
{
    for (auto currentVertex : verticesList)
    {
        if(currentVertex->getData() == value)
            return currentVertex;
    }

    return nullptr;
}

void simpleGraph::makeWhiteGraph()
{
	for (auto& currentVertex : verticesList)
	{
		currentVertex->vertexColor = eColors::White;
	}
}

bool simpleGraph::isAdjacent(vertex& vertexSource, vertex& vertexDestination)
{
	for (auto adjacentVertex : vertexSource.getEdgesList())
	{
		if (adjacentVertex == &vertexDestination)
		{
			return true;
		}
	}

	return false;
}

bool simpleGraph::addEdge(vertex& vertexSource, vertex& vertexDestination)
{
    if(!isAdjacent(vertexSource,vertexDestination))
    {
        vertexSource.addNeighbor(&vertexDestination);
        numOfEdges++;
        return true;
    }
    else
        return false;
}


bool simpleGraph::addEdgeUI(int vertexSourceValue, int vertexDestinationValue)
{
    if(vertexSourceValue <= 0 || vertexDestinationValue <= 0 ||
       vertexSourceValue > numOfVertices || vertexDestinationValue > numOfVertices)
    {
        cout << "invalid input";
        exit(1);
    }

    vertex* sourcePtr = findVertexByValue(vertexSourceValue);
    vertex* destinationPtr = findVertexByValue(vertexDestinationValue);

    if(sourcePtr == nullptr || destinationPtr == nullptr)
    {
        cout << "invalid input";
        exit(1);
    }

    return addEdge(*sourcePtr, *destinationPtr);
}

bool simpleGraph::removeEdge(vertex& vertexSource, vertex& vertexDestination)
{
    bool isRemoved = vertexSource.removeNeighbor(&vertexDestination);

    if (isRemoved)
    {
        numOfEdges--;
    }
    else
    {
        cout << "This edge does not exist in the graph!" << endl;
    }

	return isRemoved;
}

void simpleGraph::DFSEndList(list<int>& endList)
{
	for (auto& currentVertex : verticesList)
	{
		if (currentVertex->vertexColor == eColors::White)
		{
			visitVertexAddToList(*currentVertex, endList);
		}
	}

    this->makeWhiteGraph();
}

void simpleGraph::visitVertexAddToList(vertex& currentVertex, list<int>& endList)
{
	currentVertex.vertexColor = eColors::Gray;

	for (auto neighborVertex : currentVertex.getEdgesList())
	{
		if (neighborVertex->vertexColor == eColors::White)
		{
			visitVertexAddToList(*(neighborVertex), endList);
		}
	}

	currentVertex.vertexColor = eColors::Black;
	endList.push_back(currentVertex.getData());
}

void simpleGraph:: DFSWithEndListToSuperGraph(list<int>& listWorkingOrder, simpleGraph& superGraph)
{
	for (int vertexValue :listWorkingOrder)
	{
        vertex* currentVertex = this->findVertexByValue(vertexValue);
		if (currentVertex->vertexColor == eColors::White)
		{
			currentVertex->vertexColor = eColors::Gray;
            currentVertex->myRootVertex = currentVertex;
            auto* superGraphVertex = new vertex(*currentVertex);
            superGraph.addVertex(*superGraphVertex);

            visitVertexAddToSuperGraph(*currentVertex,*superGraphVertex,superGraph);

			currentVertex->vertexColor = eColors::Black;
		}
		// (else) Vertex is black
	}

    this->makeWhiteGraph();
}

void simpleGraph::visitVertexAddToSuperGraph(vertex& fatherVertex, vertex& rootVertexInSuper, simpleGraph& superGraph)
{
    for (auto neighborVertex : fatherVertex.getEdgesList())
    {
        if (neighborVertex->vertexColor == eColors::White)
        {
            neighborVertex->vertexColor = eColors::Gray;
            neighborVertex->myRootVertex = fatherVertex.myRootVertex;
            visitVertexAddToSuperGraph(*neighborVertex, rootVertexInSuper, superGraph);
            neighborVertex->vertexColor = eColors::Black;
        }
        else if (neighborVertex->vertexColor == eColors::Black)
        {
            if (neighborVertex->myRootVertex->getData() != rootVertexInSuper.getData())
            {
                vertex* vertexInSuperGraph = superGraph.findVertexByValue(neighborVertex->myRootVertex->getData());
                superGraph.addEdge(*vertexInSuperGraph,rootVertexInSuper);
            }
        }
        //else is gray
    }
}

void simpleGraph::makeTransposeGraphFrom(simpleGraph* sourceGraph)
{
	this->makeEmptyGraph(sourceGraph->numOfVertices);

	for (auto& sourceVertexInSourceGraph : sourceGraph->verticesList)
	{
        auto itVertexDestinationTGraph = verticesList.begin();
        advance(itVertexDestinationTGraph, sourceVertexInSourceGraph->getData()-1);

		for (auto vertexNeighbor : sourceVertexInSourceGraph->getEdgesList())
		{
            auto itVertexSourceTGraph = verticesList.begin();
            advance(itVertexSourceTGraph, vertexNeighbor->getData()-1);

            (*itVertexSourceTGraph)->addNeighbor(*itVertexDestinationTGraph);
            this->numOfEdges++;
		}
	}
}

simpleGraph& simpleGraph::makeSuperGraphKSAlgo()
{
	// DFS on G Graph & build endList
	list<int> endList;
    this->DFSEndList(endList);
    endList.reverse();

	// Build G transpose
	simpleGraph transposedGraph;
    transposedGraph.makeTransposeGraphFrom(this);

	// DFS on G transpose with reversed endList
	simpleGraph* superGraph = new simpleGraph();
	superGraph->makeEmptyGraph(0);
	transposedGraph.DFSWithEndListToSuperGraph(endList, *superGraph);

	return *superGraph;
}

void simpleGraph::printGraph()
{
	cout << "Graph has " << numOfVertices << " vertices and " << numOfEdges << " edges:" << endl;

	for (auto& currentVertex : verticesList)
	{
		cout << "Vertex " << currentVertex->getData() << " has edges to: ";
		list<vertex*> edges = currentVertex->getEdgesList();
		for (const auto& neighbor : edges)
		{
			cout << neighbor->getData() << " ";
		}
		cout << endl;
	}
}

simpleGraph:: ~simpleGraph()
{
    for (auto currentVertex : verticesList)
    {
        delete currentVertex;
    }
    verticesList.clear();
}