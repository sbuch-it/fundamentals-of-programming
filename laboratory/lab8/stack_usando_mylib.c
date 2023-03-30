#include <stdio.h>
#include "mylib.h"

int main() {
	float buffer[N];
	float n;
	int tos = 0;
	
	while (1) {
		char c;
		printf("Inserisci nuovo elemento (1) o estrai (2)?\n");
		scanf("%c", &c);
		fflush(stdin);
		
		if (c == '1') {
			printf("Elemento?\n");
			scanf("%f", &n);
			fflush(stdin);
			
			if (!push(buffer, n, &tos)) { // if (push(...) == 0)
				printf("Pila piena!\n");
			} else {
				printf("Ho inserito: %f\n", n);
			}
		
			stampa_pila(buffer, tos);
		} else if (c == '2') {
			if (!pop(buffer, &n, &tos)) {
				printf("Pila vuota!\n");
			} else {
				printf("Ho rimosso: %f\n", n);
			}
			
			stampa_pila(buffer, tos);
		} else {
			printf("Digita 1 o 2!\n");
		}
	}
	
	return 0;
}
