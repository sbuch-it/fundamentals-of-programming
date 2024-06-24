/*Acquisizione dati formattati finche' !=EOF 
con controllo per inserimento corretto*/
#include <stdio.h>
#include<stdlib.h>

int main()
{
 	char month[80];
 	int day,year;
  	int count;
  
  	printf("Inserire una data nella forma 1 Aprile 2015\n");

	while((count=scanf("%d %s %d",&day, month,&year))!=EOF)
	{
		if(count>=0 && count<3){
			printf("Errore nell'inserimento dati\n");
			printf("Inserisci correttamente una data nella forma 1 Aprile 2015\n");
			
			while(getchar()!='\n'); //salta i rimanenti dati immessi
		}
		else
		{
			printf("Il numero di valori inseriti e' %d\n",count);
			printf("Il mese inserito e' %s\n", month);
			printf("La data e':%d %s %d\n",day,month,year);
		}
	}

 	system("PAUSE");
}
