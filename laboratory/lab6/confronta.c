#include<stdio.h>
#define LEN 20

main(){
	char string1[LEN],string2[LEN];
	char *pt1, *pt2;
	int len1=0, len2=0;
	
	puts("Inserisci la prima stringa:");
	scanf("%s",string1);
	
	puts("Inserisci la seconda stringa:");
	scanf("%s",string2);
	
	pt1=string1;
	pt2=string2;
	
	while(*(pt1+len1)!='\0'){
		len1++;
		
	} 
	
	while(*(pt2+len2)!='\0'){
		len2++;
	//	p2++;
	} 
	
	while(*pt1 !='\0' && *pt2 !='\0' && *pt1 == *pt2){
		++pt1;
		++pt2;
	} 
	
	if(pt1 == string1+len1 && pt2 == string2+len2)  puts("Le stringhe sono uguali");
	else puts("Le stringhe sono diverse");
	
}
