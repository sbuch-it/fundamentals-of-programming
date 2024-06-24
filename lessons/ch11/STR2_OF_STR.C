/* mostra come utilizzare strutture di strutture.
riceve in input le coordinate del rettangolo (non controlla che queste siano "corrette")
e ne calcola l'area */
#include<stdio.h>

typedef struct {
	int x;
	int y;
} coord; 

typedef struct {
	coord alto_sx;
	coord basso_dx;
} rettangolo;
	
long calcola_area(rettangolo);

main()
{ 
	rettangolo mio_box;

	/*inserimento delle coordinate*/
	printf("\n inserire la coordinata x in alto a sinistra:");
	scanf("%d",&mio_box.alto_sx.x);

	printf("\n inserire la coordinata y in alto a sinistra:");
	scanf("%d",&mio_box.alto_sx.y);

	printf("\n inserire la coordinata x in basso a destra:");
	scanf("%d",&mio_box.basso_dx.x);

	printf("\n inserire la coordinata y in basso a destra:");
	scanf("%d",&mio_box.basso_dx.y);

	printf("l'area e' %ld unita'",calcola_area(mio_box));
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
