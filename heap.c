#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  heapElem elemento = pq->heapArray[0];

  if(pq->size == 0) return NULL;
  
  return elemento.data;
}



void heap_push(Heap* pq, void* data, int priority){

  if(pq->size == pq->capac){
    pq->heapArray = realloc(pq->heapArray, (2 * pq->capac) + 1);
  }

  heapElem elemento;
  elemento.data = data;
  elemento.priority = priority;
  pq->size++;
  int indiceElem = pq->size - 1;
  int indicePadre = (pq->size - 1) / 2;

  pq->heapArray[indiceElem] = elemento;

  while(pq->heapArray[indiceElem] > pq->heapArray[indicePadre]){
    heapElem aux = pq->heapArray[indicePadre];
    pq->heapArray[indicePadre] = pq->heapArray[indiceElem];
    pq->heapArray[indiceElem] = aux;
    indiceElem = indicePadre;
    indicePadre = (indiceElem) / 2;
  }
  
  
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* heap;
  heap = (Heap*) malloc(sizeof(Heap));
  heap->heapArray = (heapElem*) malloc (3 * sizeof(heapElem));
  heap->size = 0;
  heap->capac = 3;

   return heap;
}
