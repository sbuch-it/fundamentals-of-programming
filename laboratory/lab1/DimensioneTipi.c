/* 
Programma per la determinazione delle dimensioni dei tipi
*/

#include<stdio.h>



main(){
	/*tipi base*/
	puts("Utlizzo di sizeof() per determinare la dimensione dei tipi di base:");
	printf("\nIl tipo char occupa: %d bytes",sizeof(char));
	printf("\nIl tipo int occupa: %d bytes",sizeof(int));
	printf("\nIl tipo float occupa: %d bytes",sizeof(float));
	printf("\nIl tipo double occupa: %d bytes",sizeof(double));
	
	/*modificatori di tipo*/
	puts("Utlizzo di sizeof() per determinare la dimensione dei modificatori dei tipi di base:");
	printf("\nIl tipo short int occupa: %d bytes",sizeof(short int));
	printf("\nIl tipo long int occupa: %d bytes",sizeof(long int));
	printf("\nIl tipo long long int occupa: %d bytes",sizeof(long long int));
	
}
