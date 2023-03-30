/*
programma che acquisisce lo stato (eta' e genere) di un individuo e 
lo "classifica" come giovane o anziano, femmina o maschio.
Assegnamento logico passo intermedio.
*/
#include<stdio.h>
#include<stdlib.h>

main(){
	unsigned int eta;
	char genere;
	int giovane=0, anziano=0; //variabili "booleane" relative all'eta' dell'individuo
	int femmina=0, maschio=0; //variabili "booleane" relative al genere dell'individuo
	
	/* acquisizione dati*/
	printf("\n Inserisci l'eta' e il genere dell'individuo F per femmina, M per maschio:");
	scanf("%u\n%c",&eta,&genere);
	
	/*echo dei dati*/
	printf("\nEta'=%u\t Genere=%c",eta,genere);
	
	/*classificazione stato individuo*/
	if(giovane=(eta<65)){}
	else
		anziano=(eta>=65);
	if(femmina=(genere=='F')){}
	else
		maschio=(genere=='M');
	
	/*visualizzazione*/
	if(giovane && maschio){
		printf("\nL'individuo e' un giovane maschio");
	}
	else if(giovane && femmina){
		printf("\nL'individuo e' un giovane femmina");
	}
	else if(anziano && maschio){
		printf("\nL'individuo e' un anziano maschio");
	}
	else{
		printf("\nL'individuo e' un anziano femmina");
	}
	system("PAUSE");
}
