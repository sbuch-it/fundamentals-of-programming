#include<stdio.h>
int sumVet(int *, int);

int main(){
	int  size=5,total;
	int vet[]={1,2,3,4,5};
	
	total=sumVet(vet, size);
	printf("%d\n",total);
	return 0;
}

int sumVet(int *v, int dim)
{
	if (dim==0)
	return 0;
	else
	return v[0] + sumVet(v+1,dim-1);
}
