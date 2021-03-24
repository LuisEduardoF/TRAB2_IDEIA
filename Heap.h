#ifndef HEAP
#define HEAP
typedef struct heap *tHeap;

//Inicializa a Heap com um tamanho maximo
tHeap inicializeHeap(int cap);
//Insere um elemento na heap com um peso
void insertHeap(int weight, int, tHeap);
//Retorna o menor valor da heap
int peekHeap(tHeap);
//Da pop no menor valor da heap
int extractHeap(tHeap);
//Retorna o menor peso
int minWeight(tHeap);
//Imprime os pesos da heap
void printHeap(tHeap);
//Libera a heap
void freeHeap(tHeap);
#endif