/*Esempio di utilizzo corretto di feof
restituisce 0 quando incontra EOF (tentativo di leggere oltre la fine del file)
Acquisizione dei dati di un cliente da tastira e scrittura su un file*/
#include<stdio.h>

int main(){
	FILE *fp;
	
	if((fp=fopen("clients.txt","w"))==NULL)
	{
		puts("Errore di apertura del file\n");
	}
	else
	{
		puts("\n Inserisci n.conto, nome, e saldo:");
		puts("\n Ctrl Z per terminare\n");
		
		unsigned int account;
		char name[30];
		double balance;
		
		/*attenzione all'ordine logico delle istruzioni*/
		scanf("%d%s%lf",&account,name,&balance);
		while(!feof(stdin))
		{
			fprintf(fp,"%d %s %f\n",account,name,balance);
			puts("Prossimo record?\n");
			scanf("%d%s%lf",&account,name,&balance);
		}
		fclose(fp);
	}
}
