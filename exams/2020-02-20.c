#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct{
	int n, r, c;
	int id_righe[N], id_colonne[N];
	double valori[N];
} mat_sparsa;

int carica_matrice(FILE *puntatore_file, double M[][N], int *r, int *c);
int sparsifica(double M[][N], int r, int c, mat_sparsa *dato);
void stampa_densa(mat_sparsa matrice_sparso);

int main(){
	
	FILE *puntatore_file;
	
	int esito, indice;
	double matrice_denso[N][N];
	int r,c;
	int *puntatore_r=&r;
	int *puntatore_c=&c;
	mat_sparsa dato;
	
	mat_sparsa *puntatore_dato=&dato;
	
	if((puntatore_file=fopen("matrice.txt","r"))==NULL){
		printf("Errore nell'apertura del file\n");
        exit(EXIT_FAILURE);
	}
	
	esito=carica_matrice(puntatore_file, matrice_denso, puntatore_r, puntatore_c);	
    
	if(esito==1){
    	printf("\nIl numero di righe e' %d e il numero di colonne e' %d\n",r,c);
    	indice=sparsifica(matrice_denso, r, c, puntatore_dato);
    	printf("\nIndice della riga con minor numero di elementi nulli e' %d\n",indice);
    	stampa_densa(dato);
	}else{
		printf("Errore di lettura del file");
	}

	fclose(puntatore_file);
}

int carica_matrice(FILE *puntatore_file, double M[][N], int *r, int *c){
	
	int i, j;
	int status;
	
	status=fscanf(puntatore_file,"%d %d",r,c);
	if(status!=2)
		return 0;
	
	for(i=0;i<*r;i++){
		for(j=0;j<*c;j++){
        	status=fscanf(puntatore_file,"%lf ",&M[i][j]);
        	if(status!=1)
				return 0;
		}
	}
	
	if(i==*r && j==*c)
		return 1;
	else
		return 0;
		
}

int sparsifica(double M[][N], int r, int c, mat_sparsa *dato){
	
	int i,j;
	int indice_id=0, conta=0, righe=r, max=0, indice_max;
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			
			if(M[i][j]!=0.0){
				dato->id_righe[indice_id]=i;
				dato->id_colonne[indice_id]=j;
				dato->valori[indice_id]=M[i][j];
				indice_id++;
				conta++;
			}
					
		}
		
		if(conta==c)
			righe--;
		
		if(conta>max){
			max=conta;
			indice_max=i;
		}	
		
		conta=0;	
	}
	
	dato->n=indice_id;
	dato->r=righe;
	dato->c=indice_id-righe;
	
	return indice_max;
}

void stampa_densa(mat_sparsa m){
	
}
