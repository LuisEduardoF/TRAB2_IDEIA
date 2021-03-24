#ifndef GRAPH
#define GRAPH
typedef struct graph *tGraph;

tGraph inicializeGraph(int v_n, int e_n);
void addConection(int source, int target, double weight, tGraph);
void printAdjencyMatrix(tGraph);
void printNeighbours(tGraph);
void Djikstra(int source, tGraph g);
void freeGraph(tGraph);

#endif