/*calcola il fattoriale in modo ricorsivo*/
#include<stdio.h>

unsigned long long int factorial(unsigned int);

int main(void) 
{
	// durante ogni iterazione calcola factorial(i)
 	//e stampa il risultato
 	unsigned int i;
	for(i=0;i<=21;i++)
	printf("%u!=%llu\n",i,factorial(i));
}


unsigned long long int factorial(unsigned int n) 
{
	if (n <= 1)// passo di base
	return 1;
	else  //passo di ricorsione
	return (n * factorial(n-1));
}
