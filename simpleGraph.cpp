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

vertex* simpleGraph:: findVertexByValue(const int value)
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


void simpleGraph::addEdgeUI(int vertexSourceValue, int vertexDestinationValue)
{
    vertex* sourcePtr = nullptr;
    vertex* destinationPtr = nullptr;

    for (auto& currentVertex : verticesList)
    {
        if(currentVertex->getData() == vertexSourceValue)
        {
            sourcePtr = currentVertex;
        }
        else if(currentVertex->getData() == vertexDestinationValue)
        {
            destinationPtr = currentVertex;
        }

        if(sourcePtr != nullptr && destinationPtr != nullptr)
            break;
    }

    if(sourcePtr == nullptr || destinationPtr == nullptr)
    {
        cout << "PROBLEM there are not such a vertex" << endl;
    }
    else
    {
        if(!addEdge(*sourcePtr,*destinationPtr))
            cout << "The edge is already in the graph" << endl;
    }
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

list<vertex*> simpleGraph::DFSEndList(list<vertex*>& endList)
{
	for (auto& currentVertex : verticesList)
	{
		if (currentVertex->vertexColor == eColors::White)
		{
			visitVertexAddToList(*currentVertex, endList);
		}
	}

    this->makeWhiteGraph();

	return endList;
}

list<vertex*> simpleGraph:: reverseListInMyGraph(list<vertex*>& endList)
{
    list<vertex*> reverseList;
    for (auto it:endList)
    {
        auto itVertexInMyGraph = this->verticesList.begin();
        advance(itVertexInMyGraph, it->getData()-1);

        reverseList.push_back(*itVertexInMyGraph);
    }

    return reverseList;
}

void simpleGraph::visitVertexAddToList(vertex& currentVertex, list<vertex*>& endList)
{
	currentVertex.vertexColor = eColors::Gray;
	list<vertex*> vertexEdges = currentVertex.getEdgesList();

	for (auto neighborVertex : vertexEdges)
	{
		if (neighborVertex->vertexColor == eColors::White)
		{
			visitVertexAddToList(*(neighborVertex), endList);
		}
	}

	currentVertex.vertexColor = eColors::Black;
	endList.push_back(&currentVertex);
}

void simpleGraph:: DFSWithEndListToSuperGraph(list<vertex*>& listWorkingOrder, simpleGraph& superGraph)
{
	for (auto currentVertex:listWorkingOrder)
	{
		if (currentVertex->vertexColor == eColors::White)
		{
			currentVertex->vertexColor = eColors::Gray;
            currentVertex->myRootVertex = currentVertex;
            auto* superGraphVertex = new vertex(*currentVertex);
            superGraph.addVertex(*superGraphVertex);

            visitVertexAddToSuperGraph(currentVertex->getEdgesList(),*currentVertex,*superGraphVertex,superGraph);

			currentVertex->vertexColor = eColors::Black;
		}
		// (else) Vertex is black
	}

    for (auto currentVertex:listWorkingOrder)
    {
        currentVertex->vertexColor = eColors::White;
    }
}

void simpleGraph::visitVertexAddToSuperGraph(list<vertex*>& listNeighbor, vertex& rootVertex, vertex& rootVertexInSuper, simpleGraph& superGraph)
{
    for (auto neighborVertex : listNeighbor)//
    {
        if (neighborVertex->vertexColor == eColors::White)
        {
            neighborVertex->vertexColor = eColors::Gray;
            neighborVertex->myRootVertex = &rootVertex;
            visitVertexAddToSuperGraph(neighborVertex->getEdgesList(), rootVertex, rootVertexInSuper,superGraph);
            neighborVertex->vertexColor = eColors::Black;
        }
        else if (neighborVertex->vertexColor == eColors::Black)
        {
            if (neighborVertex->myRootVertex != &rootVertex)
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
	list<vertex*> endList;
    endList = this->DFSEndList(endList);

	// Build G transpose
	simpleGraph transposedGraph;
    transposedGraph.makeTransposeGraphFrom(this);
    list<vertex*> reverseEndListInTransposeGraph = transposedGraph.reverseListInMyGraph(endList);

	// DFS on G transpose with reversed endList
	simpleGraph* superGraph = new simpleGraph();
	superGraph->makeEmptyGraph(0);
	transposedGraph.DFSWithEndListToSuperGraph(reverseEndListInTransposeGraph, *superGraph);

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