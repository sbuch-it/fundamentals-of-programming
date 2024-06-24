#include<stdio.h>

main()
{
	int i,n,s=0;
	
	printf("Inserisci un intero n:\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		s+=i;
	}
	printf("La somma dei primi %d numeri e' %d",n,s);
}
