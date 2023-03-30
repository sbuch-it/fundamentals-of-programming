#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct {
	float isee_minimo, isee_massimo, prima_rata, seconda_rata, totale;
} tupla;

int leggi_tupla(FILE *puntatore_file, tupla *riga_file);
int leggi_file(int max_tuple, tupla fasce[]);
int ricerca(int num_tuple, tupla fasce[], float x);

int main(){
	
	int num_tuple, indice_x;
	char input;
	tupla fasce[N];
	float isee_dichiarato;
	
	do{
		printf("Ha intenzione di dichiarare il suo isee? (y - n) : ");
		scanf("%c",&input);
		while(getchar()!='\n');
	}while(input!='y' && input!='n');
	
	num_tuple=leggi_file(N, fasce);
	
	if(input=='y'){
		
		printf("Inserire il proprio ISEE : ");
		scanf("%f",&isee_dichiarato);

		indice_x=ricerca(num_tuple,fasce,isee_dichiarato);

		printf("Il suo ISEE e' compreso tra %f e %f euro.\n",fasce[indice_x].isee_minimo,fasce[indice_x].isee_massimo);
		printf("Prima rata : %f , seconda rata: %f , Totale : %f\n",fasce[indice_x].prima_rata,fasce[indice_x].seconda_rata,fasce[indice_x].totale);
	}else{
		
		printf("Rata corrispondente alla fascia di reddito piu' alta: \n");
		printf("Prima rata : %f , seconda rata: %f , Totale : %f\n",fasce[num_tuple-1].prima_rata,fasce[num_tuple-1].seconda_rata,fasce[num_tuple-1].totale);
	}
	
}

int leggi_tupla(FILE *puntatore_file, tupla *riga_file){
	int status;
	status=fscanf(puntatore_file,"%f%f%f%f%f", &(riga_file->isee_minimo), &(riga_file->isee_massimo), &(riga_file->prima_rata), &(riga_file->seconda_rata), &(riga_file->totale));
	
	if(status==5) status=1;
	else if(status!=EOF) status=0;
	return (status);
}

int leggi_file(int max_tuple, tupla fasce[]){
	FILE *puntatore_file;
	tupla riga_file;
	int i,status;
	
	if((puntatore_file=fopen("es1.txt","r"))==NULL){
		printf("Errore nell'apertura del file");
		exit(EXIT_FAILURE);
	}
	
	i=0;
	do{
		if((status=leggi_tupla(puntatore_file,&riga_file))==1){
			fasce[i]=riga_file;
			i++;
		}
	}while(status==1 && i<max_tuple);
	
	fclose(puntatore_file);
	
	if(status==0){
		printf("\n Errore nel formato dei dati\n");
		printf("Dati caricati: %d\n",i);
	}
	else if(status!=EOF){
		printf("\n Il file contiene troppi dati\n");
		printf("Dati caricati: %d\n",i);
	}
    return i;
}

int ricerca(int num_tuple, tupla fasce[], float x){
	int found=0;
	int end=num_tuple-1, start=0, middle;
	
	do{
		middle=(end+start)/2;
		
		if(x>=fasce[middle].isee_minimo && x<=fasce[middle].isee_massimo)
			found=1;
		else if(x>fasce[middle].isee_massimo)
			start=middle+1;
		else
			end=middle-1;
	}while(!found && start<=end);
	return middle;
}
