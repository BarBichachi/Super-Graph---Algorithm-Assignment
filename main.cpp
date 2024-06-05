#include <iostream>
#include "simpleGraph.h"
using namespace std;

int main()
{
//    simpleGraph myGraph;
//    int numVertices, numEdges, sourceVertex, destinationVertex;
//    cout << "Creating Graph:\nPlease enter the number of vertices: ";
//    cin >> numVertices;
//    myGraph.makeEmptyGraph(numVertices);
//    cout << "Please enter number of edges: ";
//    cin >> numEdges;
//    for(int i=0;i<numEdges;i++)
//    {
//        cin >> sourceVertex >> destinationVertex;
//        myGraph.addEdgeUI(sourceVertex, destinationVertex);
//    }

    simpleGraph myGraph;
    myGraph.makeEmptyGraph(6);
    myGraph.addEdgeUI(1, 2);
    myGraph.addEdgeUI(1, 3);
    myGraph.addEdgeUI(3, 2);
    myGraph.addEdgeUI(2, 4);
    myGraph.addEdgeUI(4, 3);
    myGraph.addEdgeUI(5, 4);
    myGraph.addEdgeUI(5, 6);
    myGraph.addEdgeUI(6, 5);

    myGraph.printGraph();
    cout << endl;

    simpleGraph superGraph = myGraph.makeSuperGraphKSAlgo();
    cout << "The super graph is:" << endl;
    superGraph.printGraph();

    return 0;
}