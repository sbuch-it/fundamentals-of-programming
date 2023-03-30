/*visualizza un rettangolo di asterischi con data base e altezza
utilizzando una funzione di visualizzazione*/
#include<stdio.h>

/*dichiarazione della funzione*/
void visualizza_rettangolo(int,int);

int main(){
	int b,h; //base e altezza del rettangolo
	
	/*Acquisizione dati*/
	printf("\nInserisci due interi positivi per la base e l'altezza del rettangolo:");
	scanf("%d%d",&b,&h);
	printf("\nbase:%d\taltezza:%d\n",b,h); //echo
	
	/*visualizzazione del rettangolo*/
	visualizza_rettangolo(b,h);
	return 0;
}

/*definizione della funzione*/
void visualizza_rettangolo(int base,int altezza){
	int i,j;
	for(i=0;i<altezza;i++){
		for(j=0;j<base;j++){
			if(i==0||i==altezza-1) printf("*");
			else if (j==0||j==base-1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}	
}
