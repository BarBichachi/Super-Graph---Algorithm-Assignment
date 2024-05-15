#include <iostream>
#include "simpleGraph.h"
using namespace std;

int main()
{
    simpleGraph G;
    G.makeEmptyGraph(4);
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 4);
    G.removeEdge(1, 3);
    bool isTrue = G.isAdjacent(1, 3);
    cout << "Hello, World!" << endl;

    return 0;
}