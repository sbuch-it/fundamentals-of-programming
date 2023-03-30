#include <stdio.h>
#define N 5

unsigned int push(float*, float, int*);
unsigned int pop(float*, float*, int*);
unsigned int enqueue(float*, float, int, int*);
unsigned int dequeue(float*, float*, int*, int);
void stampa_pila(float* buf, int t);
void stampa_coda(float* buf, int h, int t);

