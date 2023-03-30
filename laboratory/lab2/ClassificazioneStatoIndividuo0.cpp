/*
programma che acquisisce lo stato (eta' e genere) di un individuo e 
lo "classifica" come giovane o anziano, femmina o maschio.
Visualizza il risultato "completo".
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

	/*versione successiva: visualizzazione completa*/
	if(eta<65 && genere=='M'){
		printf("\nL'individuo e' un giovane maschio");
	}
	else if(eta<65 && genere=='F'){
		printf("\nL'individuo e' un giovane femmina");
	}
	else if(eta>=65 && genere=='M'){
		printf("\nL'individuo e' un anziano maschio");
	}
	else{
		printf("\nL'individuo e' un anziano femmina");
	}
	system("PAUSE");
}
