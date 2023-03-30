#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 200

typedef struct{
	char andata[MAX];
	char ritorno[MAX];
} dati;

int load_data(FILE *puntatore_file, dati voli[], int max_voli);
int tratte_andata_ritorno(dati voli[], int n, dati tratte[]);
void visualizza_tratte(dati tratte[], int k);

int main(){
	
	FILE *puntatore_file;
	dati voli[MAX];
	dati tratte[MAX];
	int n,k;
	
	if((puntatore_file=fopen("input.txt","r"))==NULL){
		printf("Errore nell'apertura del file\n");
        exit(EXIT_FAILURE);
	}
	
	n=load_data(puntatore_file, voli, MAX);
	
	if(n==0)
		printf("Errore nella lettura del file\n");
	else if(n==1){
		printf("Errore, verranno utilizzati solo i primi 200 voli\n");
		n=200;
	}else{
		printf("Sono stati caricati correttamente %d voli\n\n",n);
	}
		
	k=tratte_andata_ritorno(voli, n, tratte);
	
	visualizza_tratte(tratte, k);
		
	fclose(puntatore_file);
		
}

int load_data(FILE *puntatore_file, dati voli[], int max_voli){

	dati volo;
	int i, status;
	
	i=0;
	while((status=fscanf(puntatore_file, "%s%s", volo.andata, volo.ritorno))!=EOF && i<max_voli){
		if(status==2) {
			voli[i]=volo;
			i++;
		}
		else if(status>=0 && status<2){
			status=0;
		}
	}
	
	if(status==0){
		printf("\n ***Errore nel formato***\n");
		printf("***Usa solo i primi %d dati\n",i);
		return 0;
	}
	else if(status!=EOF){
		printf("\n ***il file contiene troppi dati***\n");
		printf("***Usa solo i primi %d dati\n",i);
		return 1;
	}
	
	return i;
}

int tratte_andata_ritorno(dati voli[], int n, dati tratte[]){
	int i,j,k=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			
			if(!strcmp(voli[i].andata, voli[j].ritorno) && !strcmp(voli[i].ritorno, voli[j].andata)){
				
				strcpy (tratte[k].andata, voli[i].andata);
				strcpy (tratte[k].ritorno, voli[i].ritorno);
				k++;	
			}	
		}
	}
	return k;
}

void visualizza_tratte(dati tratte[], int k){
	int i;
	printf("numero di tratte andata e ritorno: %d\n",k);
	for(i=0;i<k;i++){
		printf("%s %s\n",tratte[i].andata,tratte[i].ritorno);
	}
}
