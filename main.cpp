#include "simpleGraph.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    simpleGraph myGraph;
    int numVertices, numEdges, vertexSourceValue, vertexDestinationValue;

    cout << "Creating Graph:\nPlease enter the number of vertices: ";
    cin >> numVertices;
    myGraph.makeEmptyGraph(numVertices);
    cout << "Please enter number of edges: ";
    cin >> numEdges;

    for(int i=0;i<numEdges;i++)
    {
        cin >> vertexSourceValue >> vertexDestinationValue;
        if(!myGraph.addEdgeUI(vertexSourceValue, vertexDestinationValue) )
        {
            cout << "invalid input";
            exit(1);
        }
    }
    cout << endl;

    simpleGraph superGraph = myGraph.makeSuperGraphKSAlgo();
    cout << "The super graph is:" << endl;
    superGraph.printGraph();

    return 0;
}