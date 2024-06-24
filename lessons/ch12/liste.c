#include <stdio.h>
#include <stdlib.h>

// elemento base della lista
typedef struct element {
	int data;
	struct element* next;
} elem;

int main()
{
	elem* head = NULL; // puntatore al primo elemento della lista
	elem* tail = NULL; // puntatore all'ultimo elemento della lista
	int n; // elemento inserito dall'utente

	do {
		// n = intero inserito dall'utente
		printf("Inserisci un intero!\n"); scanf("%d", &n);

		// allochiamo un nuovo elemento della lista
		elem* new = malloc(sizeof(elem));

		// memorizziamo n sul nuovo elemento della lista
		new->data = n;
		new->next = NULL;

		// colleghiamo la lista esistente al nuovo elemento
		if (head == NULL)
			head = new;
		else
			tail->next = new;
		tail = new;

		// stampiamo il nuovo vettore
		printf("Contenuto vettore:\n");
		elem* cur = head;
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
		printf("\n");
	} while (n != 0);

	return 0;
}	
