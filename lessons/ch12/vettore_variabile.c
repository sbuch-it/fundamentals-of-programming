#include <stdio.h>
#include <stdlib.h>

int main() {
	int* v = NULL; // puntatore al vettore di valori inseriti
	int valori_inseriti = 0; // numero di valori inseriti
	int n, i; // valore inserito dall'utente e contatore

	do {
		// n = intero inserito dall'utente
		printf("Inserisci un intero!\n"); scanf("%d", &n);

		// salviamo un riferimento all'attuale vettore
		int* v_old = v;

		// allochiamo un nuovo vettore di dimensione maggiore (+1)
		v = malloc((valori_inseriti + 1) * sizeof(int));

		// copiamo il vecchio vettore sul nuovo
		for (i = 0; i < valori_inseriti; i++)
			v[i] = v_old[i];

		// liberiamo l'area del vecchio vettore
		free(v_old);

		// aggiungiamo n al nuovo vettore
		v[valori_inseriti++] = n;

		// stampiamo il nuovo vettore
		printf("Contenuto vettore:\n");
		for (i = 0; i < valori_inseriti; i++)
			printf("%d ", v[i]);
		printf("\n");
	} while (n != 0);

	return 0;
}


