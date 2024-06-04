#include <iostream>
#include "simpleGraph.h"
using namespace std;

int main()
{
    simpleGraph myGraph;
    int numVertices, numEdges, sourceVertex, destinationVertex;
    cout << "Creating Graph:\nPlease enter the number of vertices: ";
    cin >> numVertices;
    myGraph.makeEmptyGraph(numVertices);
    cout << "Please enter number of edges: ";
    cin >> numEdges;
    for(int i=0;i<numEdges;i++)
    {
        cin >> sourceVertex >> destinationVertex;
        myGraph.addEdge(sourceVertex, destinationVertex);
    }


//    simpleGraph G;

//    G.makeEmptyGraph(7);
//    G.addEdge(1, 2);
//    G.addEdge(1, 3);
//    G.addEdge(2, 1);
//    G.addEdge(2, 3);
//    G.addEdge(2, 4);
//    G.addEdge(2, 5);
//    G.addEdge(3, 1);
//    G.addEdge(3, 2);
//    G.addEdge(3, 6);
//    G.addEdge(3, 7);
//    G.addEdge(4, 2);
//    G.addEdge(5, 2);
//    G.addEdge(6, 3);

////    G.makeEmptyGraph(6);
//    G.addEdge(1, 2);
//    G.addEdge(1, 3);
//    G.addEdge(3, 2);
//    G.addEdge(2, 4);
//    G.addEdge(4, 3);
//    G.addEdge(5, 4);
//    G.addEdge(5, 6);
//    G.addEdge(6, 5);
//    G.printGraph();
    cout << endl;

    simpleGraph superGraph = myGraph.makeSuperGraphKSAlgo();
    cout << "The super graph is:" << endl;
    superGraph.printGraph();

    return 0;
}