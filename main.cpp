#include <iostream>
#include "simpleGraph.h"
using namespace std;

int main()
{
    simpleGraph G;
    G.makeEmptyGraph(6);
    
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(3, 2);
    G.addEdge(2, 4);
    G.addEdge(4, 3);
    G.addEdge(5, 4);
    G.addEdge(5, 6);
    G.addEdge(6, 5);
    G.printGraph();
    simpleGraph superGraph = G.makeSuperGraphKSAlgo();
    superGraph.printGraph();

    cout << "Hello, World!" << endl;

    return 0;
}