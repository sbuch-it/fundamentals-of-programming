/*Converte le misure sulla base dell'unita' sorgente e di quella destinazione.
le unita' di misura sono descritte nel file units.txt (unita' di misura  abbreviazione tipologia quantita')*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_LEN 30 //spazio riservato per il nome dell'unita'
#define ABBREV_LEN 15 //spazio riservato per l'abbreviazione dell'unita'
#define cl_LEN 20 //spazio riservato per la cle delle misure
#define NOT_FOUND -1 //valore per unita' non trovata
#define MAX_UNITS 20 //numero massimo di unita' di misura gestite

/*definisco un nuovo tipo per la struttura rappresentante un'unita' di misura*/
typedef struct {     
	char name[NAME_LEN];       //stringa come grammi
	char abbrev[ABBREV_LEN];   //stringa di abbreviazione come g
	char cl[cl_LEN];     //stringa come peso, distanza, pressione...
	double standard;           //numero di unita' equivalenti, ad es. 0.001 
	} unit_t;
	
int fscanf_unit(FILE *fp, unit_t *unitp);
void load_units(int max_units, unit_t units[], int *unit_sizep);
int search(const unit_t units[], const char *target,int n);
double convert(double quantity, double old_stand, double new_stand);
	
main(){
	unit_t units[MAX_UNITS]; //vettore per la memorizzazione delle info relative alle unita' di misura
	int i,num_units;           //numero di elementi units in uso 
	char old_units[NAME_LEN];  //unita' di misura da convertire
	char new_units[NAME_LEN];  //unita' di misura in cui convertire
	int status;                 //stato dell'acquisizione
	double quantity;             //valora da convertire
	int old_index, new_index;    //indici del vettore corrispondenti a old_units e new_units
	
	
	/*Carica il database delle unita' di misura*/
	load_units(MAX_UNITS,units, &num_units);

	for(i=0;i<num_units;i++){
		printf("units[%d]:%s\t%s\t%s\t%lf\n",i,units[i].name,units[i].abbrev,units[i].cl,units[i].standard);
	}
	
	
	/*Menu' utente*/
	printf("\n Inserisci il problema di conversione\n");
	printf("Ad es. per convertire 25 kilometri in miglia, inserisci:\n");
	printf("25 kilometri miglia\n");
	printf("oppure abbreviato,\n");
	printf("25 km mi\n");
	
	do{
	 printf("\n ***q per uscire***");
	 printf("\n oppure");	
     printf("\n Inserisci il problema di conversione:\n");
     
	if( (status=scanf("%lf %s %s",&quantity,old_units,new_units))==3){
		printf("Conversione di %f %s a %s ...\n",quantity, old_units, new_units);
		old_index=search(units, old_units, num_units);
		new_index=search(units, new_units, num_units);
		if(old_index==NOT_FOUND) printf("L'unita' %s non e' presente nel database\n",old_units);
		else if(new_index==NOT_FOUND) printf("L'unita' %s non e' presente nel database\n",new_units);
		else if(strcmp(units[old_index].cl,units[new_index].cl )!=0) 
				printf("Impossibile convertire da %s a %s \n",old_units, new_units);
		else printf("Conversione: %f %s = %f %s  \n",quantity, old_units,
				 convert(quantity,units[old_index].standard,units[new_index].standard),new_units);
	}
		
	}while(status==3);
	
	system("PAUSE");
	
    return 0;
}	
	
/*legge una riga del file e memorizza in un dato del tipo unita' di misura.
restituisce :1 per input corretto; 0 per errore; EOF per fine file*/	
int fscanf_unit(FILE *fp, unit_t *unitp){
	int status;
	status=fscanf(fp, "%s%s%s%lf", unitp->name, unitp->abbrev,unitp->cl,&unitp->standard);
	
	if(status==4) status =1;
	else if(status!=EOF) status=0;
	
	return(status);
}	

/*
Apre il file units.txt e legge i dati da salvare nell'array units fino alla fine del file.
Interrompe la lettura se ci sono piu' di unit_max valori nel file 
o se viene letto un dato non valido*/
void load_units(int max_units,unit_t units[], int *unit_sizep){
	FILE *input;
	unit_t data;
	int i, status;
	
	/*acquisisci i dati dal file*/
	if((input=fopen("units.txt","r"))==NULL){
		printf("Errore nell'apertura del file\n");
        exit(EXIT_FAILURE);
	}
	
	i=0;
	
	do{
		if((status=fscanf_unit(input,&data))==1){
		   units[i]=data;
		   i++;
		}
	}while(status==1 && i<max_units);
	
	fclose(input);
	
	/*visualizza un messaggio di errore in caso di uscita prematura*/
	if(status==0){
		printf("\n ***Errore nel formato***\n");
		printf("***Usa solo i primi %d dati\n",i);
	}
	else if(status!=EOF){
		printf("\n ***il file contiene troppi dati***\n");
		printf("***Usa solo i primi %d dati\n",i);
	}
	
	*unit_sizep=i;
}

/*cerca la stringa target nei campi name e abbrev delle prime n celle dell'array units.
restituisce l'indice dell'array che contiene l'elemento trovato o NOT FOUND*/
int search(const unit_t units[], const char *target,int n){
	int i, found=0, k;
	
	/*confronta i campi di ciascun elemento con quelli dell'elemento da trovare*/
	i=0;
	
	while(!found && i<n){
		if( strcmp(units[i].name,target)==0 || strcmp(units[i].abbrev,target)==0)
			found=1;
		else
			i++;
	}
	
	if(found) k=i;
	else k=NOT_FOUND;
	
	return(k);
	
	
	
	
}

/*Converte una misura in un'altra date le rappresentazioni di entrambe nell'unita' di misura standard.
ad es. convertire 24 piedi in iarde data l'unita' standard in pollici:
	quantity=24, old_stand=12 (1 piede=12 pollici), new_stand=36 (1 iarde= 36 pollici), risultato=24*12/36*/
double convert(double quantity, double old_stand, double new_stand){
	return(quantity*old_stand/new_stand);
}
