#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 20 //dimensione massima per array

//definisco una struttura per rappresentare un punto
typedef struct{
	int x, y; //coordinate di un punto
} punto;

//definisco una struttura per rappresentare un segmento
typedef struct{
	punto a, b; //estremi di un segmento
} segmento;

int leggi_segmenti(FILE *puntatore_file, segmento array[], int m);
int controlla_poligono(segmento array[], int num_segmenti, double *puntatore_perimetro);
void stampa(segmento array[], int num_segmenti, double perimetro);

int main(){
	
	FILE *puntatore_file;
	
	segmento array[N]; //array per memorizzare tutti i segmenti
	int num_segmenti; //numero di segmenti effettivi
	int esito; //memorizza l'esito della funzione controlla_poligono
	double perimetro=0.; //memorizza il valore del perimetro del poligono
	
	double *puntatore_perimetro=&perimetro; //variabile puntatore a perimetro per modificare il valore nella funzione controlla_poligono
	
	//lettura del file di testo e in caso di errore lo comunica all'utente e interrompe il programma
	if((puntatore_file=fopen("lista_segmenti.txt","r"))==NULL){
		printf("Errore nell'apertura del file\n");
        exit(EXIT_FAILURE);
	}
	
	//funzione leggi_segmenti ritorna il numero effettivo di segmenti letti e memorizza il valore in num_segmenti
	num_segmenti=leggi_segmenti(puntatore_file, array, N);
	
	printf("I segmenti correttamente caricati sono %d \n\n",num_segmenti);
	
	//funzione controlla_poligono restituisce 1 o 0 in base all'esito e lo memorizza in esito
	esito=controlla_poligono(array, num_segmenti, puntatore_perimetro);
	
	//se l'esito è positivo chiama la funzione stampa che stampa la lista dei segmenti e il perimetro
	if(esito)
		stampa(array, num_segmenti, perimetro);
		
	fclose(puntatore_file);
	
}

int leggi_segmenti(FILE *puntatore_file, segmento array[], int m){

	segmento riga; //variabile per memorizzare una riga del file di testo
	int i; //variabile per memorizzare il numero di segmenti effettivi
	int status; //variabile per controllare se la lettura da file è stata eseguita correttamente
	
	i=0;
	while((status=fscanf(puntatore_file, "%d %d %d %d", &riga.a.x, &riga.a.y, &riga.b.x, &riga.b.y))!=EOF && i<m){
		if(status==4) {
			array[i]=riga;
			i++;
		}
		else if(status>=0 && status<4){
			status=0;
		}
	}
	
	if(status==0 || status!=EOF)
		printf("alcuni dati sono stati ignorati\n");
	
	return i;
}

int controlla_poligono(segmento array[], int num_segmenti, double *puntatore_perimetro){
	
	int i, j, check=0; //la variabile check memorizza quante coppie di punti sono uguali
	
	for(i=0;i<num_segmenti;i++){
		for(j=i+1;j<num_segmenti;j++){
			
			/*
			controlla se i due estremi della riga i-esima del file sono uguali ad un altro punto delle righe sottostanti
			la i-esima riga, se la condizione è verificata incrementa la variabile check.
			*/
			
			if(array[i].a.x == array[j].a.x && array[i].a.y == array[j].a.y)
				check++;
				
			if(array[i].b.x == array[j].b.x && array[i].b.y == array[j].b.y)
				check++;
				
			if(array[i].a.x == array[j].b.x && array[i].a.y == array[j].b.y)
				check++;
				
			if(array[i].b.x == array[j].a.x && array[i].b.y == array[j].a.y)
				check++;
		}
	}
	
	/*se il numero delle coppie è uguale al numero di segmenti significa che è possibile costruire un
	poligono perché per ogni estremo di un segmento è presente un altro segmento che ha lo stesso punto
	come estremo.
	*/ 
	
	if(check==num_segmenti){
		
		/*viene applicata la formula per il calcolo della somma delle lunghezze euclidee dei segmenti
		e viene salvata nella variabile puntatore, la quale punta alla variabile perimetro e quindi aggiorna il suo valore.
		*/
		
		for(i=0;i<num_segmenti;i++){
			*puntatore_perimetro=*puntatore_perimetro+sqrt(pow(array[i].a.x-array[i].b.x,2)+pow(array[i].a.y-array[i].b.y,2));
		}
		return 1;
		
	}

	return 0;
}

void stampa(segmento array[], int num_segmenti, double perimetro){
	
	int i;
	
	printf("Lista dei segmenti: \n");
	
	//esegue la stampa dei segmenti e del perimetro nella forma specificata
	
	for(i=0;i<num_segmenti;i++){
		printf("(%d,%d)  (%d,%d) \n",array[i].a.x,array[i].a.y,array[i].b.x,array[i].b.y);
	}
	
	printf("\nPerimetro: \n%f",perimetro);
}

