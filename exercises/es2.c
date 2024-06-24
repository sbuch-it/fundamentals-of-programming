#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define STRING_MAX 20
#define CAMERE_MAX 20

//Struttura camera per rappresentare una riga del file
typedef struct {
	double prezzo;  //Prezzo per una notte
	char tipo[STRING_MAX];  //Tipo di camera
	int giardino, disponibile;  //Disponibilità del giardino e numero di posti disponibili in albergo
} camera;

int fscanf_camera(FILE *fp, camera *cp);
int load_albergo(camera albergo[]);
void acquisisci_tipo(camera albergo[], int, char input_camera[]);
int controlla_tipo(camera albergo[], int, char tipo_camera[]);
double calcolo(camera albergo[], int , int, char tipo_camera[]);
void verifica(camera albergo[], int , char tipo_camera[]);
int fprintf_camera(camera albergo[], int, char tipo_camera[]);

int main(){
	
	camera albergo[CAMERE_MAX];  //Array per memorizzare tutti i tipi di camere dell'albergo
	char tipo_camera[STRING_MAX];  //Variabile per memorizzare l'input dell'utente relativo al tipo di camera
	int n_tipo_camere;  //Numero effettivo del tipo di camere presenti nel file
	int giorni, operazione, i;  //Variabili necessarie per memorizzare l'input dell'utente
	
	n_tipo_camere=load_albergo(albergo);  //La funzione restituisce il numero di righe del file
	
	do{
		//Menù per interagire con l'utente
		printf("Programma che gestisce le camere di un albergo \n\n");
		printf("0. Uscire dal programma \n");
		printf("1. Calcolare il prezzo di un soggiorno, fornendo in input il numero di giorni e il tipo di camera \n");
		printf("2. Verificare la disponibilita' di un tipo di camera fornito da input e se e' presente il giardino \n");
		printf("3. Effettuare una prenotazione di una camera, modificando il numero di camere disponibili per il tipo richiesto \n");
		printf("\n Quale operazione si desidera effettuare: ");
		scanf("%d",&operazione);
	
		switch (operazione) {
			case 0:
				break;
			case 1:
				printf("Numero di giorni del soggiorno: ");
				scanf("%d",&giorni);
				acquisisci_tipo(albergo, n_tipo_camere, tipo_camera);
				printf("Il soggiorno costa %f euro per una notte \n",calcolo(albergo, n_tipo_camere, giorni, tipo_camera));
				break;
				
			case 2:
				acquisisci_tipo(albergo,n_tipo_camere,tipo_camera);  
				verifica(albergo, n_tipo_camere, tipo_camera);
				break;
				
			case 3:
				acquisisci_tipo(albergo, n_tipo_camere, tipo_camera);
				if(!fprintf_camera(albergo, n_tipo_camere, tipo_camera))
					printf("\n Non e' stato possibile effettuare la prenotazione \n");
				else
					printf("\n Prenotazione effettuata con successo \n");	
				break;
				
			default :
				printf("Operazione Errata \n");
				break;
		}
		system ("PAUSE");
		system ("CLS");
	}while(operazione!=0);
	
}

//Funione che legge una riga del file e restituisce l'esito della lettura
int fscanf_camera(FILE *pf, camera *cp){
	int status;
	status=fscanf(pf, "%s%lf%d%d", cp->tipo, &cp->prezzo, &cp->giardino, &cp->disponibile);
	
	if(status==4) status = 1;
	else if(status!=EOF) status = 0;
	
	return(status);
}

//Funzione che salva i dati presenti nel file nell'array albergo
int load_albergo(camera albergo[]){
	int i=0, status;
	FILE *puntatore_file;

	if((puntatore_file=fopen("input.txt","r"))==NULL){
		printf("Errore nell'apertura del file \n");
        exit(EXIT_FAILURE);
	}
	
	do{
		if((status=fscanf_camera(puntatore_file,&albergo[i]))==1) i++;
	}while(status==1 && i<CAMERE_MAX);
	
	fclose(puntatore_file);
	
	if(status==0) 
		printf("Errore nel formato dei dati \n");
	else if(status!=EOF) 
		printf("I file contiene troppi dati \n");

	return i;
}

//Funzione per acquisire un tipo di camera
void acquisisci_tipo(camera albergo[], int n, char input_camera[]){ 
	int i;
	printf("I tipi di camera sono: \n");
	for(i=0;i<n;i++){
		printf("- %s \n",albergo[i].tipo);
	}
	
	do{
		printf("Fornire un tipo di camera: ");
		scanf("%s",input_camera);
	}while(controlla_tipo(albergo, n, input_camera));  //Chiamata alla funzione controlla_tipo per verificare se l'input è corretto
}

//Funzione che controlla se un tipo di camera è presente nell'array albergo e restituisce esito
int controlla_tipo(camera albergo[], int n, char tipo_camera[]){
	int i;
	for(i=0;i<n;i++){
		if(!strcmp(albergo[i].tipo, tipo_camera))
			return 0;
	}
	return 1;
}

//Funzione che calcola il prezzo totale di un soggiorno
double calcolo(camera albergo[], int n, int giorni,char tipo_camera[]){
	int i;
	double costo=0.;
	for(i=0;i<n;i++){
		if(!strcmp(albergo[i].tipo, tipo_camera))
			costo= (double) giorni*(albergo[i].prezzo);
	}
	return costo;
}

//Funzione che verifica la disponibilità di un tipo di camera
void verifica(camera albergo[], int n, char tipo_camera[]){
	int i;
	for(i=0;i<n;i++){
		if(!strcmp(albergo[i].tipo,tipo_camera) && albergo[i].disponibile==0)
			printf("Il tipo di camera non e' disponibile \n");
		if(!strcmp(albergo[i].tipo,tipo_camera) && albergo[i].disponibile>0 && albergo[i].giardino==1)
			printf("Il tipo di camera e' disponibile e ha il giardino \n");	
		if(!strcmp(albergo[i].tipo,tipo_camera) && albergo[i].disponibile>0 && albergo[i].giardino==0)
			printf("Il tipo di camera e' disponibile e non ha il giardino \n");
	}
}

//Funzione che salva nel file la prenotazione dell'utente se essa risulta possibile
int fprintf_camera(camera albergo[], int n, char tipo_camera[]){
	camera *cp;
	int i,status;
	FILE *puntatore_file;
	
	for(i=0;i<n;i++){
		if(!strcmp(albergo[i].tipo,tipo_camera) && albergo[i].disponibile==0)
			return 0;
		if(!strcmp(albergo[i].tipo,tipo_camera) && albergo[i].disponibile>0)
			(albergo[i].disponibile)--;
	}
	
	if((puntatore_file=fopen("input.txt","w"))==NULL){
		printf("Errore nell'apertura del file \n");
        exit(EXIT_FAILURE);
	}
	
	for(i=0; i<n; i++){
		cp=&albergo[i];
		status=fprintf(puntatore_file, "%s %lf %d %d\n", cp->tipo, cp->prezzo, cp->giardino, cp->disponibile);
	}
	
	fclose(puntatore_file);
	
	return status;
}
