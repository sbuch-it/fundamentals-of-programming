/*Riconoscimento di un pattern in un testo digitato da tastiera 
e letto carattere per carattere.Versione if else if*/

#include<stdio.h>

main(){
	char ch; //per lettura
	int stato=0;//indica lo stato di riconoscimento del pattern
	
	printf("Inserisci il testo:\n");
	
	do{
		ch=getchar();
		if(ch=='c' || ch=='C') stato=1;
		else if(ch=='i' || ch=='I'){
			if(stato==1) stato++;
			else stato=0;
		}
		else if(ch=='a' || ch=='A'){
			if(stato==2) stato++;
			else stato=0;
		}
		else if(ch=='o' || ch=='O'){
			if(stato==3) stato++;
			else stato=0;
		}
		else stato=0;
	}while(stato<4);//ciclo potenzialmente infinito
	
	printf("\nPattern riconosciuto.\n");

}
