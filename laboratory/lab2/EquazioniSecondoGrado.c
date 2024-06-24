/*
Soluzione equazione di secondo grado della forma ax^2+bx+c=0 
Versione base: si suppone a diverso da zero*/
#include<stdio.h>
#include<math.h>

main()
{
	int a,b,c; //coefficienti dell'equazione
	double delta; //delta
	float sol1,sol2; //soluzioni 
	/*acquisizione dati*/
	printf("Risolvi l'equazione ax^2+bx+c=0\n");
	printf("Inserisci a, b, c in questo ordine\n");
	scanf("%d%d%d",&a,&b,&c);
	
	/*soluzione dell'equazione. Si suppone che a>0.*/
	delta=pow(b,2.0)-4*a*c;
	/*le condizioni su delta sono mutuamente esclusive*/
	if(delta<0){
		printf("\nNessuna soluzione reale");
	}
	else if(delta==0){
		printf("\nDue soluzioni coincidenti %f\n",-(float)b/(2*a));
	}
	else{
		printf("\nDue soluzioni reali.");
		
		sol1=(-b-sqrt(delta))/(2*a);
		sol2=(-b+sqrt(delta))/(2*a);
		printf("\nSoluzione1=%f\t Soluzione 2=%f\n",sol1,sol2);
	}
	
	system("PAUSE");
}
