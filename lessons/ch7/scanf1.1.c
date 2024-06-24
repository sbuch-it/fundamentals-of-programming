/*Inserimento dati formattati con scanf: 
con controllo, ma SBAGLIATO.*/

#include <stdio.h>

int main()
{
  char month[80];
  int day,year;
  int count=0;
  
  printf("Inserire una data nella forma 1 Aprile 2015\n");
  do{
		  count=scanf("%d %s %d",&day, month,&year);
		  
		  printf("Il numero di valori inseriti e' %d\n",count);
		  printf("Il mese inserito e' %s\n", month);
		  printf("La data e':%d %s %d\n",day,month,year);
	}while(count<3);

}
