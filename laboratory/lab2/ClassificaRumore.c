/*
programma per la classificazione dei livelli di rumore.
Importanza dell'ordine di elaborazione. 
*/

#include<stdio.h>
#include<stdlib.h>

main(){
	int rumore;  //rumore espresso in decibel
	
	/*acquisizione dati*/
	printf("\nInserisci il valore del rumore rilevato in decibel:");
	scanf("%d",&rumore);
	/*classificazione del valore di rumore*/
	if(rumore<=50)
		printf("\n Il rumore rivelato e' tranquillo\n");
	else if(rumore <=70)
		printf("\n Il rumore rivelato e' percepito\n");
	else if(rumore <=90)
		printf("\n Il rumore rivelato e' fastidioso\n");
	else if(rumore <=110)
		printf("\n Il rumore rivelato e' molto fastidioso\n");
	else 
		printf("\n Il rumore rivelato e' intollerabile\n");
		
}
