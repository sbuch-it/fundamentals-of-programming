/*
Programma che legge un testo carattere per carattere e verifica se sono presenti lettere maiuscole e le conta.
L'immissione termina con EOF. versione while.
*/

#include<stdio.h>

main(){
	int stop=0,trovato=0;
	int count=0;
	int ch; //attenzione: EOF e' solitamente -1
		
	puts("\nInserisci il testo carattere per carattere:");
	puts("Termina il testo con <Ctrl z>");
		
	while((ch=getchar())!=EOF){
		printf("%c",ch);//echo
		if(ch>=65 && ch<=90) {
			trovato=1;
			count++;
		}
	}
	
	if(trovato) printf("\nNel testo sono presenti %d lettere maiuscole",count);
	else printf("\nNel testo non sono presenti lettere maiuscole");
	
}
