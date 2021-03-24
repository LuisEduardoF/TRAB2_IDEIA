#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"
typedef struct data{
    int weight;
    int data;
}tData;
struct heap{
    tData* heap;
    int cap;
    int nElements;
};
int parent(int i) { return i/2; } 
int left(int i) { return 2*i; }   
int right(int i) { return 2*i + 1; } 
void swap(tData *x, tData *y) { tData temp = *x; *x = *y; *y = temp; } 

void minHeapify(int i, tHeap h){
    int l = left(i); 
    int r = right(i); 
    int smallest = i;
    if (l <= h->nElements && h->heap[l].weight < h->heap[i].weight) 
        smallest = l; 
    if (r <= h->nElements && h->heap[r].weight < h->heap[smallest].weight) 
        smallest = r; 
    if (smallest != i) { 
        swap(&h->heap[i], &h->heap[smallest]); 
        minHeapify(smallest, h); 
    } 
}
tHeap inicializeHeap(int cap){
    tHeap new = malloc(sizeof(struct heap));

    new->heap = malloc(sizeof(tData)*cap);
    new->cap = cap;
    new->nElements = 0;

    return new;
}
void insertHeap(int weight, int data, tHeap h){
    if(h->nElements < h->cap){
        h->nElements++;
        int newPos = h->nElements - 1;
        h->heap[newPos].data = data;
        h->heap[newPos].weight = weight;
        while(newPos != 0 && h->heap[parent(newPos)].weight > h->heap[newPos].weight){ 
            swap(&h->heap[newPos], &h->heap[parent(newPos)]); 
            newPos = parent(newPos); 
        } 
    }
}
int peekHeap(tHeap h){ if (h->nElements <= 0) return -1; else return h->heap[0].data;}
int extractHeap(tHeap h){
    if (h->nElements <= 0) 
        return -1; 
    if (h->nElements == 1){ 
        h->nElements--; 
        return h->heap[0].data; 
    }
    int root = h->heap[0].data; 
    h->heap[0] = h->heap[h->nElements-1]; 
    h->nElements--; 
    minHeapify(0, h);
    return root;
}
int minWeight(tHeap h){ return h->heap[0].weight; }
void printHeap(tHeap h){
    for(int i = 0; i < h->nElements; i++){
        printf("%d ( %d )\n", h->heap[i].weight, h->heap[i].data);
    }
}
void freeHeap(tHeap h){
    free(h->heap);
    free(h);
}