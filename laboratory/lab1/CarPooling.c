/*
programma che calcola la spesa giornaliera per andare a lavoro in auto
*/

#include<stdio.h>

main(){
	/*input*/
	int percorso; //kilometri totali percorsi al giorno
	float costo_carb; //costo del carburante al litro
	float media; //media dei kilometri al litro
	float costo_parc; //costo parcheggio
	float pedaggio; //pedaggio al giorno
	
	/*output*/
	float costo_giorno; //costo giornaliero del carburante 
	
	/*acquisizione dati*/
	puts("\nInserisci il numero di km percorsi al giorno:");
	scanf("%d",&percorso);
	
	puts("\nInserisci il costo del carburante al litro:");
	scanf("%f",&costo_carb);
	
	puts("\nInserisci la media dei kilometri fatti con un litro:");
	scanf("%f",&media);
	
	puts("\nInserisci il costo del parcheggio:");
	scanf("%f",&costo_parc);
	
	puts("\nInserisci il pedaggio:");
	scanf("%f",&pedaggio);
	
	
	/*calcolo del costo giornaliero di carburante per il percorso*/
	costo_giorno=percorso/media*costo_carb; 
	
	printf("\nIl costo giornaliero di carburante per il percorso e': %f\n",costo_giorno+costo_parc+pedaggio);
	
}
