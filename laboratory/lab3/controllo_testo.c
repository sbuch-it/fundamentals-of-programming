#include<stdlib.h>
#include<stdio.h>

main(){
	int stop=0,trovato=0;
	int count=0;
	char ch;
		
	printf("\nInserisci il testo carattere per carattere:\n");
	printf("Termina il testo con '.'\n");
		
	do{
		ch=getchar();
		printf("%c",ch);//echo
		if(ch=='.') stop=1;
		else if(ch>=65 && ch<=90) {
			trovato=1;
			count++;
		}
	}while(!stop);
	
	if(trovato) printf("\nNel testo sono presenti %d lettere maiuscole",count);
	else printf("\nNel testo non sono presenti lettere maiuscole");
	
	system("PAUSE");
}
