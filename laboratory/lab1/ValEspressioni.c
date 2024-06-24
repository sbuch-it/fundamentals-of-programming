/*
Programma per la valutazione di alcune espressioni: precedenze e conversioni
*/

#include<stdio.h>


main(){
	int i=10,j=4,k,n;
	float x, y,z;
	
	puts("Programma per la valutazione di alcune espressioni:");
	x=i+3.5*j;
	printf("\nx=i+3.5*j vale %f",x);
	
	k=(x-i)/j;
	printf("\nk=(x-i)/j vale %d",k);
	
	n=x-i/j;
	printf("\nn=x-i/j vale %d",n);
	
	y=(x-i)/j;
	printf("\ny=(x-i)/j vale %f",y);
	
	z=x-i/j;
	printf("\nz=x-i/j vale %f",z);
	
	z=x-(float)i/j;
	printf("\nz=x-(float)i/j vale %f",z);
	
	/*esempio di valore inaspettato!*/
	x=1.e8,y=1.;
	printf("\n%f %f",x+y-x,x-x+y);
	
}
