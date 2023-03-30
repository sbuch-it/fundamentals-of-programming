/* il programma definisce una coda come un array ad anello sul quale effettuare operazioni di enqueue e dequeue*/
#include<stdio.h>
#include<stdlib.h>

#define N 100

typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean enqueue(float * buffer, int head, int *pt_tail,float value);
Boolean dequeue(float * buffer, int *pt_head, int tail, float *pt_value);

main(){
	float buffer[N]; //array per memorizzare gli elementi della coda
	float value; //elemento da inserire in o estrarre da la coda
	int head,tail; //testa e coda 
	Boolean result;//notifica il valore ritornato dalle funzioni push() e pop()
	
	/*inizializzo la testa e la coda*/
	head=tail=0;
	
	/*definire come inserire i dati...*/
	
	result=enqueue(buffer, head, &tail, value);
	if(result==FALSE){
		printf("Coda piena: Impossibile l'inserimento di %f\n",value);
	}
	else{
		if(head<tail){
			int i;
			for(i=head;i<tail;i++) printf("%f\n", buffer[i]);
		}
		else {
			int i;
			for(i=head;i<N;i++) printf("%f\n", buffer[i]);
			for(i=0;i<tail;i++) printf("%f\n", buffer[i]);
		}
	}
	
	
	result=dequeue(buffer, &head, tail, &value);
	if(result==FALSE){
		printf("Coda vuota: Impossibile l'estrazione\n");
	}

	
}


Boolean enqueue(float * buffer, int head, int *pt_tail,float value){
	if(head == *pt_tail+1 || (head==0 && *pt_tail==N-2))  return FALSE;
	else{
		buffer[*pt_tail]=value;
		if(*pt_tail==N-1) *pt_tail=0;
		else (*pt_tail)++;
	}
	   return TRUE;
}


Boolean dequeue(float * buffer, int *pt_head, int tail, float *pt_value){
	if(*pt_head == tail) return FALSE;
	else{
		*pt_value=buffer[*pt_head];
		if(*pt_head == N-1) *pt_head=0;
		else (*pt_head)++;
	}
	return TRUE;
}

