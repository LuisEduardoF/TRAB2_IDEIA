#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct node{
    int info;
    struct node *prox;
}*tNode;
tNode inicializaNode(int info){
    tNode new = malloc(sizeof(struct node));
    new->info = info;
    new->prox = NULL;
    return new;
}
struct list{
    tNode fst, end;
    int lenght;
};
int isEmptyList(tList l){
    return l->fst == NULL;
}
int ExistList(tList l){
    return l != NULL;
}
tList inicializeList(){
    tList new = malloc(sizeof(struct list));
    new->fst = new->end = NULL;
    new->lenght = 0;
    return new;
}
int lenght(tList L){
    return L->lenght;
}
void append(int info, tList L){
    if(ExistList(L)){
        tNode c = inicializaNode(info);
        if(isEmptyList(L)){
            L->fst = L->end = c;
        }
        else{
            L->end->prox = c;
            L->end = c;
        }
        L->lenght++;
    }
}
void printList(tList L){
    if(ExistList(L)){
        if(!isEmptyList(L)){
            for(tNode p = L->fst; p != NULL; p = p->prox){
                printf("%d ", p->info);
            } 
        }
        printf("\n");
    }
}
void freeList(tList L){
    if(ExistList(L)){
        if(!isEmptyList(L)){
            tNode aux = NULL;
            for(tNode p = L->fst; p != NULL; p = aux){
                aux = p->prox;
                free(p);
            }
        }
        free(L);
    }
}
ListIterator next(ListIterator l){
    tNode p = l;
    return p->prox;
}
ListIterator begin(tList l){
    return l->fst;
}
ListIterator end(tList l){
    return l->end;
}
int info(ListIterator l){
    tNode p = l;
    return p->info;
}