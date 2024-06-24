/*determina la lunghezza di una stringa inserita da tastiera*/
#include<stdio.h>
#define LEN 30 //parola di lungh.max esofagodermatodigiunoplastica

main(){
	char string[LEN];
	char *pt_st;
	int len=0;
	
	puts("Inserisci una stringa:");
	scanf("%s",string);
	
	pt_st=string;
	
	while(*pt_st!='\0'){
		len++;
		pt_st++;
	} 
	
	printf("La stringa inserita e':%s\n",string);
	printf("ed e' lunga %d caratteri",len);
	
	
}
