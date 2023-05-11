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
    pq->heapArray = (heapElem *) realloc(pq->heapArray, pq->capac * sizeof(heapElem*));
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
 heapElem aux = pq->heapArray[0];
  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->heapArray[pq->size - 1] = aux;
  int posicion = 0;
  aux = pq->heapArray[0];
  
  while(1){
    if(pq->heapArray[posicion].priority > pq->heapArray[2 * posicion + 1].priority) break;
    if(pq->heapArray[posicion].priority > pq->heapArray[2 * posicion + 2].priority) break;

    if(pq->heapArray[2 * posicion + 1].priority > pq->heapArray[2 * posicion + 2].priority){
      pq->heapArray[posicion] = pq->heapArray[2 * posicion + 1];
      pq->heapArray[2 * posicion + 1] = aux;
      posicion = posicion * 2 + 1;
    }else{
      pq->heapArray[posicion] = pq->heapArray[2 * posicion + 2];
      pq->heapArray[2 * posicion + 2] = aux;
      posicion = posicion * 2 + 2;
      
    }
  }
  pq->size--;
  
}

Heap* createHeap(){
  Heap* heap;
  heap = (Heap*) malloc(sizeof(Heap));
  heap->heapArray = (heapElem*) malloc (3 * sizeof(heapElem));
  heap->size = 0;
  heap->capac = 3;

   return heap;
}
