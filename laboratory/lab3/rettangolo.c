#include<stdlib.h>
#include<stdio.h>

main(){
	int base,altezza;
	int i,j;
	
	/*Acquisizione dati*/
	printf("\nInserisci due interi positivi per la base e l'altezza del rettangolo:");
	scanf("%d%d",&base,&altezza);
	printf("\nbase:%d\taltezza:%d\n",base,altezza); //echo
	
	for(i=0;i<altezza;i++){
		for(j=0;j<base;j++){
			if(i==0||i==altezza-1) printf("*");
			else if (j==0||j==base-1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	system("PAUSE");
}
