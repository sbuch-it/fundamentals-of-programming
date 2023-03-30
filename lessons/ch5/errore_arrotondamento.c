/*Un programma dai risultati inaspettati. Problema di arrotondamento*/

#include<stdio.h>
#define N 10000000

main()
{
	float S=0.,x=7.;
	unsigned int i,iS=0, ix=7;
	
	for(i=0;i<N;i++)
	{
		S+=x;
		iS+=ix;
	}
	printf("Using integers: %d x %d=%d\n",ix, N,iS);
	printf("Using float: %f x %d=%f\n",x, N,S);
}
