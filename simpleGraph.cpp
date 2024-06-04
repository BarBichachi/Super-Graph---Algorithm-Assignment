#include "simpleGraph.h"

void simpleGraph::makeEmptyGraph(int desiredNumOfVertices)
{
	this->numOfVertices = 0;
	this->numOfEdges = 0;

	for (int i = 1; i <= desiredNumOfVertices; i++)
	{
		addVertex(i);
	}
}

void simpleGraph::addVertex(int dataOfVertex)
{
	auto * currentVertex = new vertex(dataOfVertex);
	verticesList.push_back((*currentVertex));
	(this->numOfVertices)++;
}

void simpleGraph::makeWhiteGraph()
{
	for (auto& currentVertex : verticesList)
	{
		currentVertex.vertexColor = eColors::White;
	}
}

bool simpleGraph::isAdjacent(int vertexSourceValue, int vertexDestinationValue)
{
	auto vertexSource = this->verticesList.begin();
	advance(vertexSource, vertexSourceValue - 1);

	set<vertex*> vertexSourceEdgesList = (*vertexSource).getEdgesList();

	for (auto vertex : vertexSourceEdgesList)
	{
		if (vertex->getData() == vertexDestinationValue)
		{
			return true;
		}
	}

	return false;
}

void simpleGraph::addEdge(int vertexSourceValue, int vertexDestinationValue)
{
    for (auto& vertexSource : verticesList)
    {
        if(vertexSource.getData()==vertexSourceValue)
        {
            for (auto& vertexDestination : verticesList)
            {
                if(vertexDestination.getData()==vertexDestinationValue)
                {
                    vertexSource.addNeighbor(&vertexDestination);
                    numOfEdges++;
                    return;
                }
            }
        }
    }
    cout << "\n\n problem\n\n";
//	if (vertexDestinationValue > numOfVertices || vertexSourceValue > numOfVertices)
//	{
//		cout << "One of the vertices does not exist in the graph!" << endl;
//	}
//	else if (vertexSourceValue == vertexDestinationValue)
//	{
//		cout << "Can't make an edge from the source vertex to itself!" << endl;
//	}
//	else
//	{
//		auto vertexSource = this->verticesList.begin();
//		advance(vertexSource, vertexSourceValue - 1);
//
//		auto vertexDestination = this->verticesList.begin();
//		advance(vertexDestination, vertexDestinationValue - 1);
//
//		(*vertexSource).addNeighbor(&(*vertexDestination));
//		numOfEdges++;
//	}
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
	list<int> endList;

	for (auto& currentVertex : verticesList)
	{
		if (currentVertex.vertexColor == eColors::White)
		{
			visitVertexAddToList(currentVertex, endList);
		}
	}

	return endList;
}

void simpleGraph::visitVertexAddToList(vertex& currentVertex, list<int>& endList)
{
	currentVertex.vertexColor = eColors::Gray;
	set<vertex*> vertexEdges = currentVertex.getEdgesList();

	for (auto neighborVertex : vertexEdges)
	{
		if (neighborVertex->vertexColor == eColors::White)
		{
			visitVertexAddToList(*(neighborVertex), endList);
		}
	}

	currentVertex.vertexColor = eColors::Black;
	endList.push_back(currentVertex.getData());
}

list<tree*> simpleGraph::DFSTrees(list<int> listWorkingOrder, simpleGraph& superGraph)
{
	list<tree*> DFSTrees;

	for (int i = 0; i < numOfVertices; i++)
	{
		int currentVertexValue = listWorkingOrder.back();
		listWorkingOrder.pop_back();
		auto currentVertex = this->verticesList.begin();
		advance(currentVertex, currentVertexValue - 1);

		if (currentVertex->vertexColor == eColors::White)
		{
			currentVertex->myRootValue = currentVertexValue;
			currentVertex->vertexColor = eColors::Gray;
			node* currentVertexNode = new node(currentVertexValue);
			tree* currentTree = new tree(currentVertexNode);
			superGraph.addVertex(currentVertexValue);
			visitVertexAddToTree(*currentVertex, *currentVertexNode, currentVertexValue, superGraph);
			currentVertex->vertexColor = eColors::Black;
			DFSTrees.push_back(currentTree);
		}
		// (else) Vertex is black
	}

	return DFSTrees;
}

void simpleGraph::visitVertexAddToTree(vertex& currentVertex, node& currentVertexNode, int rootValue, simpleGraph& superGraph)
{
	set<vertex*> vertexEdges = currentVertex.getEdgesList();

	for (auto neighborVertex : vertexEdges)
	{
		if (neighborVertex->vertexColor == eColors::White)
		{
			neighborVertex->vertexColor = eColors::Gray;
			neighborVertex->myRootValue = rootValue;
			node* neighborVertexNode = new node(neighborVertex->getData());
			currentVertexNode.addChild(neighborVertexNode);
			visitVertexAddToTree((*neighborVertex), (*neighborVertexNode), rootValue, superGraph);
			neighborVertex->vertexColor = eColors::Black;
		}
		else if (neighborVertex->vertexColor == eColors::Black)
		{
			if (neighborVertex->myRootValue != rootValue)
			{
				superGraph.addEdge(neighborVertex->getData(), rootValue);
			}
		}
	}
}

simpleGraph simpleGraph::makeTransposeGraph()
{
	simpleGraph transposedGraph;
	transposedGraph.makeEmptyGraph(numOfVertices);

	for (auto& currentVertex : verticesList)
	{
		set<vertex*> vertexNeighborList = currentVertex.getEdgesList();

		for (auto vertexNeighbor : vertexNeighborList)
		{
			transposedGraph.addEdge(vertexNeighbor->getData(), currentVertex.getData());
		}
	}

	return transposedGraph;
}

simpleGraph& simpleGraph::makeSuperGraphKSAlgo()
{
	// DFS on G Graph & build endList
	list<int> endList = this->DFSEndList();

	// Build G transpose
	simpleGraph transposedGraph = this->makeTransposeGraph();

	// DFS on G transpose with reversed endList
	simpleGraph* superGraph = new simpleGraph();
	superGraph->makeEmptyGraph(0);
	list<tree*> treesListOfTransGraph = transposedGraph.DFSTrees(endList, *superGraph);

	return *superGraph;
}

void simpleGraph::printGraph()
{
	cout << "Graph has " << numOfVertices << " vertices and " << numOfEdges << " edges:" << endl;

	for (auto& currentVertex : verticesList)
	{
		cout << "Vertex " << currentVertex.getData() << " has edges to: ";
		set<vertex*> edges = currentVertex.getEdgesList();
		for (const auto& neighbor : edges)
		{
			cout << neighbor->getData() << " ";
		}
		cout << std::endl;
	}
}