#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
	char parola[MAX];
	char operazione[MAX];
	int posizione;
	char carattere;
} richiesta;


int carica(FILE *puntatore_file, richiesta array[], int *n);
void visualizza_dati(richiesta array[], int n);
void applica(richiesta array[], int n, int *S, int *R, int *I);
void stampa_risultato(richiesta array[], int n, int S, int R, int I);


int main(){
	
	FILE *puntatore_file;

	richiesta array[MAX];

	int n, S = 0, R = 0, I = 0, lettura;

	if ((puntatore_file = fopen("dati.txt","r")) == NULL){
		printf("Errore in apertura del file \n");
	} else {
		printf("File aperto correttamente \n");
	}
	
	lettura = carica(puntatore_file, array, &n);
	if (lettura == 0) {
		printf("Errore di lettura del file \n\n");
	} else {
		printf("File letto correttamente \n\n");	
	}

	visualizza_dati(array, n);
	
	applica(array, n, &S, &R, &I);
	
	stampa_risultato(array, n, S, R, I);

	return 0;	
}


int carica(FILE *puntatore_file, richiesta array[], int *n){
	
	int i = 0 , status;
	richiesta data;
	
	while ((status = fscanf(puntatore_file, "%s %s %d %c", 
			data.parola, data.operazione, &data.posizione, &data.carattere)) != EOF){

		if(status == 4 && i >= 0 && i <= MAX){
			array[i] = data;
		} else {
			return 0;
		}
		i++;	
	}
	*n = i;
	return 1;

}

void visualizza_dati(richiesta array[], int n){

	int i;

	for(i = 0; i < n; i++){
		printf("%s %s %d %c\n", 
			array[i].parola, array[i].operazione, array[i].posizione, array[i].carattere);
	}

}


void applica(richiesta array[], int n, int *S, int *R, int *I){
	
	int i, j, z;
	char nuova_parola[MAX];
		
	for(i = 0; i < n; i++){
			
		if(!strcmp(array[i].operazione, "SOSTITUISCI")){

			array[i].parola[array[i].posizione] = array[i].carattere;
			*S = *S + 1;

		} else if(!strcmp(array[i].operazione, "RIMUOVI")){

			for(j = array[i].posizione; j<n; j++) {
				array[i].parola[j] = array[i].parola[j+1];
			}
			*R = *R + 1;

		} else if(!strcmp(array[i].operazione, "INSERISCI")){

			for(j = 0; j<array[i].posizione; j++) {
				nuova_parola[j] = array[i].parola[j];
			}
			nuova_parola[j] = array[i].carattere;
			z = j+1;
			for(j = array[i].posizione; j<n; j++) {
				nuova_parola[z] = array[i].parola[j];
				z++;
			}
			for(j=0; j<MAX; j++) {
				array[i].parola[j] = nuova_parola[j];
			}		
			*I = *I + 1;
		}
	}

}


void stampa_risultato(richiesta array[], int n, int S, int R, int I){
	
	int i;
	
	printf("\nConteggio operazioni: %d sostituzioni, %d rimozioni, %d inserimenti \n",S,R,I);

	for(i = 0; i < n; i++){
		if (!strcmp(array[i].operazione, "SOSTITUISCI")) {
			printf("%s (S) \n", array[i].parola);
		} else if (!strcmp(array[i].operazione, "RIMUOVI")) {
			printf("%s (R) \n", array[i].parola);
		} else if (!strcmp(array[i].operazione, "INSERISCI")) {
			printf("%s (I) \n", array[i].parola);
		}
	}

}