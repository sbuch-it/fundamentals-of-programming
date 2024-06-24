/*Visualizza una stringa in ordine inverso*/
#include<stdio.h>

void invertInputRic();

int main(){
	invertInputRic();
	return 0;
}

void invertInputRic()
{ 
char ch;
scanf("%c", &ch);
if (ch != '\n') //passo di ricorsione
{
invertInputRic(); 
printf("%c", ch); 
}
else
printf("Sequenza invertita: "); //passo di base
}
