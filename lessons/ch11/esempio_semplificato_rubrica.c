#include <stdio.h>
#include <string.h>
#define N 1000

typedef struct {
	char nome[50];
	int numero;
} cont;

void inserisci_contatto(cont* x)
{
	printf("Nome? "); 
	scanf("%s", x->nome);
	printf("Numero? ");
	scanf("%d", &x->numero);
}

void stampa(cont x[], int m)
{
	int i;
	for (i = 0; i < m; i++) {
		printf("%s: %d\n", x[i].nome, x[i].numero);
	}
}

int cerca(cont x[], int m, char* nome_cercato) {
	int i;
	for (i = 0; i < m; i++) {
		if (strcmp(x[i].nome, nome_cercato) == 0) {
			return i;
		}
	}
	return -1;
}

int main()
{	
	cont rubrica[N];
	int n = 0;
	char c;
	char ricercato[100];

	do {
		inserisci_contatto(&rubrica[n]);
		n++;
		printf("Vuoi inserire altro contatto? (s/n)\n");
		fflush(stdin);
		scanf("%c", &c);
	} while (c == 's');

	stampa(rubrica, n);

	printf("Chi vuoi cercare?\n");
	scanf("%s", ricercato);

	int r = cerca(rubrica, n, ricercato);

	if (r == -1) {
		printf("Non trovato!\n");
	} else {
		printf("Numero corrispondente: %d\n", rubrica[r].numero);
	}
}