#include <stdio.h>
#define LEN 20

main(){
	char string[LEN];
	char *pt_st;
	
	puts("Inserisci una stringa:");
	scanf("%s",string);
	
	pt_st=string;
	
	while(*pt_st!='\0'){
		*pt_st=toupper(*pt_st);
		++pt_st;
	} 
	
	printf("La stringa inserita e':%s\n",string);
	
	
}
