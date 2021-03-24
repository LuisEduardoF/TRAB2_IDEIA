#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

int main(){
    tGraph g = inicializeGraph(5, 9);
    addConection(0, 1, 10, g);
    addConection(0, 3, 5, g);
    addConection(1, 3, 2, g);
    addConection(3, 1, 3, g);
    addConection(1, 2, 1, g);
    addConection(3, 2, 3, g);
    addConection(2, 4, 4, g);
    addConection(4, 2, 6, g);
    addConection(4, 0, 7, g);
    printAdjencyMatrix(g);
    printNeighbours(g);
    Djikstra(0, g);
    Djikstra(4, g);
    Djikstra(1, g);
    Djikstra(2, g);
    printAdjencyMatrix(g);
    freeGraph(g);

    return 0;
}