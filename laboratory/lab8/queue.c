#include <stdio.h>
#define N 3

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

void stampa(float* buf, int h, int t) {
	int i;
	printf("\nCODA: ");
	for (i = h; ; i = (i + 1)%N) {
		if (i == t)
			break;
		printf("%f ", buf[i]);
	}
	printf("\n\n");
}

int main() {
	float buffer[N];
	float n;
	int head = 0;
	int tail = 0;
	
	while (1) {
		char c;
		printf("Inserisci nuovo elemento (1) o estrai (2)?\n");
		scanf("%c", &c);
		fflush(stdin);
		
		if (c == '1') {
			printf("Elemento?\n");
			scanf("%f", &n);
			fflush(stdin);
			
			if (!enqueue(buffer, n, head, &tail)) { 
				printf("Coda piena!\n");
			} else {
				printf("Ho inserito: %f\n", n);
			}
		
			stampa(buffer, head, tail);
		} else if (c == '2') {
			if (!dequeue(buffer, &n, &head, tail)) {
				printf("Coda vuota!\n");
			} else {
				printf("Ho rimosso: %f\n", n);
			}
			
			stampa(buffer, head, tail);
		} else {
			printf("Digita 1 o 2!\n");
		}
	}
	
	return 0;
}
