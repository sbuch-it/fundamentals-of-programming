#include "mylib.h"

unsigned int push(float* buf, float elem, int* t) {
	if (*t == N) {
		return 0;
	} else {
		buf[*t] = elem;
		*t = *t + 1;
		return 1;
	}
}

unsigned int pop(float* buf, float* elem, int* t) {
	if (*t == 0) {
		return 0;
	} else {
		*t = *t - 1;
		*elem = buf[*t];
		return 1;
	}
}

unsigned int enqueue(float* buf, float elem, int h, int* t) {
	if (((*t + 1) % N) == h) {
		return 0;
	} else {
		buf[*t] = elem;
		*t = (*t + 1) % N;
		return 1;
	}
}

unsigned int dequeue(float* buf, float* elem, int* h, int t) {
	if (t == *h) {
		return 0;
	} else {
		*elem = buf[*h];
		*h = (*h + 1) % N;
		return 1;
	}
}

void stampa_pila(float* buf, int t) {
	int i;
	printf("\nPILA: ");
	for (i = 0; i < t; i++)
		printf("%f ", buf[i]);
	printf("\n\n");
}

void stampa_coda(float* buf, int h, int t) {
	int i;
	printf("\nCODA: ");
	for (i = h; ; i = (i + 1)%N) {
		if (i == t)
			break;
		printf("%f ", buf[i]);
	}
	printf("\n\n");
}
