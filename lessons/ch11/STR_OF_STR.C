/* mostra come utilizzare strutture di strutture.
riceve in input le coordinate del rettangolo (non controlla che queste siano "corrette")
e ne calcola l'area */
#include<stdio.h>
#include<stdlib.h>

main()
{
	int lenght, width;
	long area;

	struct coord{
		int x;
		int y;
	};
	
	struct rettangolo{
		struct coord alto_sx;
		struct coord basso_dx;
	} mio_box;
	
	/*inserimento delle coordinate*/
	printf("\n inserire la coordinata x in alto a sinistra:");
	scanf("%d",&mio_box.alto_sx.x);

	printf("\n inserire la coordinata y in alto a sinistra:");
	scanf("%d",&mio_box.alto_sx.y);

	printf("\n inserire la coordinata x in basso a destra:");
	scanf("%d",&mio_box.basso_dx.x);

	printf("\n inserire la coordinata y in basso a destra:");
	scanf("%d",&mio_box.basso_dx.y);

	/*calcolo della larghezza e altezza del rettangolo*/
	width=mio_box.basso_dx.x-mio_box.alto_sx.x;
	lenght=-(mio_box.basso_dx.y-mio_box.alto_sx.y);

	/*calcolo dell'area del rettangolo*/
	area=width*lenght;
	printf("l'area e' %ld unita'/n",area);
	system("PAUSE");
}
