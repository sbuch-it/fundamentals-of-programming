#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TLEN 50 // lunghezza massima di una stringa
#define PLEN 4 // lunghezza del pattern
#define N 100 // numero massimo di stringhe

typedef struct{
	char testo[TLEN];
	int freq[TLEN];
	int occur;
} statistica;


int leggi_seq(FILE *puntatore_file, statistica stringa[], char pattern[], int NUM, int matrix[][TLEN]);
void calcola_stat(int matrix[][TLEN], int NUM, statistica stringa[]);

int main(){
	
	int NUM;
	FILE *puntatore_file;
	
	puntatore_file = fopen("input.txt", "r");
	if(puntatore_file == NULL){
		printf("Errore di apertura del file:end\n");
	}

	fscanf(puntatore_file, "%d", &NUM);
	
	if(NUM > 0 && NUM < N){
		printf("num valido \n");
	} else if(NUM > N){
		printf("num non valido \n");
	}

	statistica stringa[NUM]; // vettore di stringhe di tipo statistica

	char pattern[] = "ABCD";
	
	int matrix[PLEN][TLEN];

	int status = leggi_seq(puntatore_file, stringa, pattern, NUM, matrix);
	
	// Stampa matrice
	for (int i=0;i<PLEN;i++){
    	for (int j=0;j<TLEN;j++){
        	printf("%d", matrix[i][j]);
    	}
		printf("\n");
	}

	calcola_stat(matrix, NUM, stringa);

	fclose(puntatore_file);
	
	return 0;
}

int leggi_seq(FILE *puntatore_file, statistica stringa[], char pattern[], int NUM, int matrix[][TLEN]){
	
	// LEGGE OGNI STRINGA E LA MEMORIZZA IN statistica stringa[]
	int indice = 0, status;

	while(!feof(puntatore_file)){

		status = fscanf(puntatore_file, "%s", stringa[indice].testo);

		if (status != 1) {
			return 0;
		}

		indice++;
	}

	// ANALIZZA LA PRIMA STRINGA E DEFINISCE LA SUA MATRICE
	indice = 0;
	for(int i=0; i<PLEN; i++){
		for(int j=0; j<TLEN; j++){
			if (pattern[i] == stringa[indice].testo[j]){
				matrix[i][j] = 1;
			} else {
				matrix[i][j] = 0;
			}		
		}
	}

	// Stampa vettore di tipo statistica
	for (int i = 0; i < NUM; i++) {
		printf("%s \n", stringa[i].testo);
	}

	return 1;	
}


void calcola_stat(int matrix[][TLEN], int NUM, statistica stringa[]){
	
	// Azzera statistiche
	for(int z=0; z<NUM; z++){
		for(int i=0; i< PLEN; i++){
			stringa[z].freq[i] = 0;
		}
	}

	// CALCOLO STATISTICA DELLA PRIMA STRINGA
	int z = 0;
	for(int i=0; i< PLEN; i++){ // scorre pattern
		for(int j=0; j< TLEN; j++){
			if(matrix[i][j] == 1){
				
				stringa[z].freq[i]++;

			}
		}
	}

	// Stampa
	char pattern[] = "ABCD";
	for(int i=0; i<PLEN; i++){
		printf("la frequenza di %c e: %d \n", pattern[i], stringa[z].freq[i]);
	}

}