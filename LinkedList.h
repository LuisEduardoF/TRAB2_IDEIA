#ifndef LINKED_LIST
#define LINKED_LIST
typedef void* ListIterator;
typedef struct list *tList;

ListIterator next(ListIterator l);
int info(ListIterator l);
ListIterator begin(tList l);
ListIterator end(tList l);
tList inicializeList();

int lenght(tList);

void append(int, tList);

void printList(tList);
void freeList(tList);

#endif