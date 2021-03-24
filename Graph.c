#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"
#include "LinkedList.h"
#include "Heap.h"
struct graph{
    double** adjency_matrix;
    tList* neighbours;
    int v_n, e_n;
};
tGraph inicializeGraph(int v_n, int e_n){
    tGraph new = malloc(sizeof(struct graph));

    new->v_n = v_n; new->e_n = e_n;
    new->adjency_matrix = malloc(sizeof(double*)*new->v_n); new->neighbours = malloc(sizeof(tList)*v_n);
    
    for(int i = 0; i < new->v_n; i++){
        new->adjency_matrix[i] = malloc(new->v_n*sizeof(double));
        for(int j = 0; j < new->v_n; j++){
            if(i == j) new->adjency_matrix[i][j] = 0;
            else new->adjency_matrix[i][j] = INT_MAX;
        }
        new->neighbours[i] = inicializeList();
    }
    return new;
}
void addConection(int source, int target, double weight, tGraph g){
    g->adjency_matrix[source][target] = weight;
    append(target, g->neighbours[source]);
}
void printAdjencyMatrix(tGraph g){
    for(int i = 0; i < g->v_n; i++){
        for(int j = 0; j < g->v_n; j++){
            if(g->adjency_matrix[i][j] == INT_MAX) printf("INF ");
            else printf("%.2f ", g->adjency_matrix[i][j]);
        }
        printf("\n");
    }
}
void printNeighbours(tGraph g){
    for(int i = 0; i < g->v_n; i++){
        printf("%d - ", i);
        printList(g->neighbours[i]);
    }
}
void Djikstra(int source, tGraph g){
    tHeap heap = inicializeHeap(g->e_n);
    int* Visitado = calloc(g->v_n, sizeof(int)); Visitado[source] = 1;
    int maxSource = source, WeightAtual = 0;
    for(int i = 0; i < g->v_n-1; i++){
        for(ListIterator p = begin(g->neighbours[source]); p != NULL; p = next(p)){
            if(!Visitado[info(p)])
                insertHeap(WeightAtual + g->adjency_matrix[source][info(p)], info(p), heap);
        }
        do{
            WeightAtual = minWeight(heap);
            source = extractHeap(heap);
        }while(Visitado[source]);
        Visitado[source] = 1;
        g->adjency_matrix[maxSource][source] = WeightAtual;
    }
    free(Visitado);
    freeHeap(heap);
}
void freeGraph(tGraph g){
    for(int i = 0; i < g->v_n; i++){
        free(g->adjency_matrix[i]);
        freeList(g->neighbours[i]);
    }
    free(g->neighbours);
    free(g->adjency_matrix);
    free(g);
}