/*
calcolo dell'area di un triangolo rettangolo
*/

#include<stdio.h>
#include<stdlib.h>

main(){
	float a,b,c; //lati di un triangolo rettangolo
	float area; //area del triangolo
	
	/*acquisizione dei dati*/
	printf("\nInserire i lati del traingolo rettangolo:");
	scanf("%f%f%f",&a,&b,&c);
	
	/*calcolo dell'area con selezione dei cateti. le condizioni sono mutuamente esclusive*/
	if(a>b) 
		if(a>c){
			printf("\nL'ipotenusa e':a\n");
			area=b*c/2;
		}
		else{
			printf("L'ipotenusa e':c\n");
			area=a*b/2;
		}
	else if (b>c){
		printf("L'ipotenusa e':b\n");
		area=a*c/2;
	}
	else { 
		printf("L'ipotenusa e':c\n");
		area=a*b/2;
	}
	
	/*visualizza l'area del triangolo rettangolo*/
	printf("L'area del triangolo e': %f\n", area);
	
	system("PAUSE");
}
