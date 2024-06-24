/*
programma che acquisisce lo stato (eta' e genere) di un individuo e 
lo "classifica" come giovane o anziano, femmina o maschio.
Visualizza il risultato dopo ciascuna selezione
*/
#include<stdio.h>
#include<stdlib.h>

main(){
	unsigned int eta;
	char genere;
	
	
	/* acquisizione dati*/
	printf("\n Inserisci l'eta' e il genere dell'individuo F per femmina, M per maschio:");
	scanf("%u\n%c",&eta,&genere);
	
	/*echo dei dati*/
	printf("\nEta'=%u\t Genere=%c",eta,genere);
	
	/*classificazione stato individuo*/
	if(eta<65){
		printf("\nL'individuo e' giovane");
	}
	else{
		printf("\nL'individuo e' anziano");
	}
	if(genere=='F'){
		printf("\nL'individuo e' una femmina");
	}
	else{
		printf("\nL'individuo e' un maschio");
	}
	

}
