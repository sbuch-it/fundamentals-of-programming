/*Riconoscimento di un pattern in un testo digitato da tastiera 
e letto carattere per carattere. Versione con switch*/

#include<stdio.h>

main(){
	char ch; //per lettura
	int stato=0;//indica lo stato di riconoscimento del pattern
	
	printf("Inserisci il testo:\n");
	
	do{
		ch=getchar();
		switch(ch){
			case 'c':
			case 'C':
				stato=1;
				break;
			case 'i':
			case 'I':
				if(stato==1) stato++;
				else stato=0;
				break;
			case 'a':
			case 'A':
				if(stato==2) stato++;
				else stato=0;
				break;
			case 'o':
			case 'O':
				if(stato==3) stato++;
				else stato=0;
				break;
			default: stato=0;
		}
		
	}while(stato<4);//ciclo potenzialmente infinito
	
	printf("\nPattern riconosciuto.\n");

}
