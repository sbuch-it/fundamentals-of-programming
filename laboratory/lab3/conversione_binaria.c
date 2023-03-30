/*
programma che converte un numero intero decimale in binario. ciclo while*/
#include<stdio.h>
#include<stdlib.h>

main(){
	int n;//numero da convertire
	int q;//quoziente
	int i=0;
	
	/*acquisizione dati*/
	printf("\n Inserisci n:\n");
	scanf("%d",&n);
	printf("%d\n",n);//echo
	
	
	q=n;
	while(q>0){
		printf("%d 2^(%d)+",q%2,i);
		q/=2;
		i++;
	}
	
	system("PAUSE");
}
