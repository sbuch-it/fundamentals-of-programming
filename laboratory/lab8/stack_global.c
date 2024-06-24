/* il programma definisce una pila come un array sul quale effettuare 
operazioni di push e pop.
Versione con variabile globale (sconsigliata)*/
#include<stdio.h>
#include<stdlib.h>

#define N 100

typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

int TOS; //testa della pila

Boolean push(float buffer[], float value);
Boolean pop(float buffer[], float *pt_value);

main(){
	float buffer[N]; //array per memorizzare gli elementi della pila
	float value; //elemento da inserire in o estrarre da la pila

	Boolean result;//notifica il valore ritornato dalle funzioni push() e pop()
	char ch;
	/*inizializzo la testa*/
	TOS=0;
	
	/*definire come inserire i dati...*/
	do{
		puts("\nInserisci 1 per push");
		puts("Inserisci 2 per pop");
		puts("Inserisci Q per uscire");
		ch=getchar();
		
		switch(ch){
		case '1':
			puts("Valore da inserire?");
			scanf("%f",&value);
			result=push(buffer,value);
			if(result==FALSE){
				printf("\nPila piena: Impossibile l'inserimento di %f\n",value);
			}
			else printf("\nElemento inserito: buffer[%d]=%f ",TOS-1,buffer[TOS-1]);
			break;
	
		case '2':
			result=pop(buffer,&value);
			if(result==FALSE){
				printf("\nPila vuota: Impossibile l'estrazione\n");
			}
			else printf("\nElemento estratto: %f TOS=%d ",value,TOS);
			break;
		default: printf("\nValore non valido:\n");
		}	
	}while(ch!='Q');
	
}


Boolean push(float buffer[], float value){
	if(TOS<N){
		buffer[TOS]=value;
		TOS++;
		return TRUE;
	}
	else
	   return FALSE;
}


Boolean pop(float buffer[], float *pt_value){
	if(TOS>0){
		TOS--;
		*pt_value=buffer[TOS];
		return TRUE;
	}
	else
	    return FALSE;
}

