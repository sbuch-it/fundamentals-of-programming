#include<stdio.h>

main(){
	int a, *p;
	p = &a;  /* p contiene l’indirizzo 
	            di a */
	*p = 30; /* la variabile puntata da p
	            vale 30 (a=30) */
	printf("%p\n", p); /* stampa l’indirizzo
	                      di a (contenuto di
	                      p) in esadecimale
	                    */
	printf("%p\n", &a);
	printf("%d\n", *p); /* stampa il valore
	                       di a (puntato da
	                       p) */
}
