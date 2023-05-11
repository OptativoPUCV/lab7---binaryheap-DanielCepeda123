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
    pq->capac = (pq->capac * 2) + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem*));
  }

  heapElem elemento;
  elemento.data = data;
  elemento.priority = priority;
  pq->size++;
  int indiceElem = pq->size - 1;
  int indicePadre = (indiceElem - 1) / 2;

  pq->heapArray[indiceElem] = elemento;

 while(pq->heapArray[indiceElem].priority > pq->heapArray[indicePadre].priority)    {
    if(pq->size == pq->capac){
    pq->capac = (pq->capac * 2) + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem*));
    }
   
    heapElem aux = pq->heapArray[indiceElem];
    pq->heapArray[indiceElem] = pq->heapArray[indicePadre];
    pq->heapArray[indicePadre] = aux;
    indiceElem = indicePadre;
    indicePadre = (indiceElem - 1) / 2;
  } 
  
}


void heap_pop(Heap* pq){
  //heapElem aux = pq->heapArray[0];

}

Heap* createHeap(){
  Heap* heap;
  heap = (Heap*) malloc(sizeof(Heap));
  heap->heapArray = (heapElem*) malloc (3 * sizeof(heapElem));
  heap->size = 0;
  heap->capac = 3;

   return heap;
}
