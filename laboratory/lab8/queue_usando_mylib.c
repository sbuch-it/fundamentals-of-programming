#include <stdio.h>
#include "mylib.h"

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
		
			stampa_coda(buffer, head, tail);
		} else if (c == '2') {
			if (!dequeue(buffer, &n, &head, tail)) {
				printf("Coda vuota!\n");
			} else {
				printf("Ho rimosso: %f\n", n);
			}
			
			stampa_coda(buffer, head, tail);
		} else {
			printf("Digita 1 o 2!\n");
		}
	}
	
	return 0;
}

