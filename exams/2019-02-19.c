#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10

typedef struct{
	double x,y,z;
	char nome[N];
} punto;

int carica_dati(FILE *puntatore_file, punto array[], int max_punti);
void calcola_distanze(punto array[], int num_punti, char lettera, float D[][N], int *puntatore_punti_selezionati);
void stampa(float matrix[][N], int z);

int main(){
	
	FILE *puntatore_file;
	punto array[N];
	int num_punti, z=0, ascii_lettera;
	float D[N][N];
	char lettera;
	
	int *puntatore_punti_selezionati=&z;
	
	if((puntatore_file=fopen("punti.txt","r"))==NULL){
		printf("Errore nell'apertura del file\n");
        exit(EXIT_FAILURE);
	}
	
	num_punti=carica_dati(puntatore_file, array, N);
	
	if(num_punti==-1)
		printf("Errore nella lettura del file\n");
	else 
		printf("Sono stati caricati correttamente %d punti\n",num_punti);
	
	do{
		printf("Inserire la lettera : ");
		scanf(" %c",&lettera);
		ascii_lettera = (int) lettera;
	}while( ascii_lettera<97 || ascii_lettera>122);
	
	
	
	
	calcola_distanze(array, num_punti, lettera, D, puntatore_punti_selezionati);
	
	printf("I punti selezionati sono %d\n\n",z);
	
	stampa(D, z);
	
	fclose(puntatore_file);
	
}

int carica_dati(FILE *puntatore_file, punto array[], int max_punti){

	punto data;
	int i, status;
	
	i=0;
	while((status=fscanf(puntatore_file, "%lf%lf%lf%s", &data.x,&data.y,&data.z,data.nome))!=EOF && i<max_punti){
		if(status==4) {
			array[i]=data;
			i++;
		}
		else if(status>=0 && status<4){
			status=0;
			return -1;
		}
	}
	return i;
}

void calcola_distanze(punto array[], int num_punti, char lettera, float D[][N], int *puntatore_punti_selezionati){
	int i, j, k=0, z=0;
	double sum;
	for(i=0;i<num_punti;i++){
		for(j=0;j<num_punti;j++){
		 	
			 if(strchr(array[i].nome, lettera) && strchr(array[j].nome, lettera)){
		 	
		 		sum=sqrt(pow(array[i].x-array[j].x,2)+pow(array[i].y-array[j].y,2)+pow(array[i].z-array[j].z,2));
		 		
		 		D[k][z]=sum;

		 		(*puntatore_punti_selezionati)++;
				z++;
		 	}
		}
		if(strchr(array[i].nome, lettera)){
			k++;
			z=0;
		}
	}
}

void stampa(float matrix[][N], int z){
	int i,j;
	for(i=0;i<sqrt(z);i++){
		for(j=0;j<sqrt(z);j++){
			printf("%f; ",matrix[i][j]);
		}
		printf("\n");
	}
}