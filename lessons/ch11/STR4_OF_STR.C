/* mostra come utilizzare strutture di strutture e array di strutture.
una funzione permette l'acquisizione dei dati(non controlla che queste siano "corrette").
una funzione calcola l'area di un rettangolo */

#include<stdio.h>
#define LEN 2

typedef struct {
	 int x;
	 int y;
} coord; 

typedef struct{
	coord alto_sx;
	coord basso_dx;
}rettangolo;
	
long calcola_area(rettangolo);
void scan_rettangolo(rettangolo *);

main()
{
	int i; 

	//rettangolo mio_box;
	rettangolo lista[LEN];

	/*inserimento delle coordinate*/
	for(i=0;i<LEN;i++) {
		scan_rettangolo(&lista[i]);
		printf("l'area e' %ld unita'",calcola_area(lista[i]));
	}
}

void scan_rettangolo(rettangolo *pt_mio_box)
{
	/*usando l'operatore .*/
	printf("\n inserire la coordinata x in alto a sinistra:");
	scanf("%d",&(*pt_mio_box).alto_sx.x);
	
	printf("\n inserire la coordinata y in alto a sinistra:");
	scanf("%d",&(*pt_mio_box).alto_sx.y);
	/*oppure usando l'operatore ->*/
	printf("\n inserire la coordinata x in basso a destra:");
	scanf("%d",&pt_mio_box->basso_dx.x);
	
	printf("\n inserire la coordinata y in basso a destra:");
	scanf("%d",&pt_mio_box->basso_dx.y);	
}

long calcola_area(rettangolo p)
{
	int lenght, width;
	long area;

	/*calcolo della larghezza e altezza del rettangolo*/
	width = p.basso_dx.x - p.alto_sx.x;
	lenght  = -( p.basso_dx.y - p.alto_sx.y );

	/*calcolo dell'area del rettangolo*/
	area = width*lenght;
	return area;
}
