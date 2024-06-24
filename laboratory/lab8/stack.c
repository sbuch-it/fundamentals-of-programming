#include <stdio.h>
#define N 3

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

void stampa(float* buf, int t) {
	int i;
	printf("\nPILA: ");
	for (i = 0; i < t; i++)
		printf("%f ", buf[i]);
	printf("\n\n");
}

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
		
			stampa(buffer, tos);
		} else if (c == '2') {
			if (!pop(buffer, &n, &tos)) {
				printf("Pila vuota!\n");
			} else {
				printf("Ho rimosso: %f\n", n);
			}
			
			stampa(buffer, tos);
		} else {
			printf("Digita 1 o 2!\n");
		}
	}
	
	return 0;
}
