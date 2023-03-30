/* il programma definisce una pila come un array sul quale effettuare operazioni di push e pop*/
#include<stdio.h>
#include<stdlib.h>

#define N 100

typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean push(float buffer[], int *pt_TOS, float value);
Boolean pop(float buffer[], int *pt_TOS, float *pt_value);

main(){
	float buffer[N]; //array per memorizzare gli elementi della pila
	float value; //elemento da inserire in o estrarre da la pila
	int TOS; //testa della pila
	Boolean result;//notifica il valore ritornato dalle funzioni push() e pop()
	
	/*inizializzo la testa*/
	TOS=0;
	
	/*definire come inserire i dati...*/
	
	result=push(buffer,&TOS,value);
	if(result==FALSE){
		printf("Pila piena: Impossibile l'inserimento di %f\n",value);
	}
	
	
	result=pop(buffer,&TOS,&value);
	if(result==FALSE){
		printf("Pila vuota: Impossibile l'estrazione\n");
	}

	
}


Boolean push(float buffer[], int *pt_TOS, float value){
	if(*pt_TOS<N){
		buffer[*pt_TOS]=value;
		(*pt_TOS)++;
		return TRUE;
	}
	else
	   return FALSE;
}


Boolean pop(float buffer[], int *pt_TOS, float *pt_value){
	if(*pt_TOS>0){
		(*pt_TOS)--;
		*pt_value=buffer[*pt_TOS];
		return TRUE;
	}
	else
	    return FALSE;
}

