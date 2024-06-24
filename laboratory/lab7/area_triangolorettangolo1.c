/*
calcolo dell'area e del perimetro di un triangolo rettangolo 
usando le funzioni
*/

#include<stdio.h>

/*dichiarazione delle funzioni*/
float calcola_perimetro(float,float,float);
float calcola_area(float,float,float);

main(){
	float lato1,lato2,lato3; //lati di un triangolo rettangolo
	float area, perimetro; //area e perimetro del triangolo
	
	/*acquisizione dei dati*/
	printf("\nInserire i lati del traingolo rettangolo:");
	scanf("%f%f%f",&lato1,&lato2,&lato3);
	
	/*calcolo dell'area con selezione dei cateti. le condizioni sono mutuamente esclusive*/
	area=calcola_area(lato1,lato2,lato3);
	/*calcola il perimetro*/
	perimetro=calcola_perimetro(lato1,lato2,lato3);
	
	/*visualizza l'area del triangolo rettangolo*/
	printf("L'area del triangolo e': %f\n", area);
	
	system("PAUSE");
}

/*definizione della funzione per il calcolo dell'area con selezione dei cateti. 
le condizioni sono mutuamente esclusive*/
float calcola_area(float a,float b,float c){
	if(a>b) 
		if(a>c){
			printf("\nL'ipotenusa e':%f\n",a);
			return(b*c/2);
		}
		else{
			printf("L'ipotenusa e':%f\n",c);
			return(a*b/2);
		}
	else if (b>c){
		printf("L'ipotenusa e':%f\n",b);
		return(a*c/2);
	}
	else { 
		printf("L'ipotenusa e':%f\n",c);
		return(a*b/2);
	}
	
}	

/*definizione della funzione per il calcolo del perimetro del triangolo*/
float calcola_perimetro(float a,float b,float c){
	return(a+b+c);
}
