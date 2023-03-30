/* 
questo programma calcola la conversione da gradi Fahrenheit a gradi Celsius.
*/

#include<stdio.h>
#include<stdlib.h>

main() {
   float tc, tf; //gradi celsius, gradi fahrenheit
   float const conv = 5./9.; //fattore di conversione
   float const offset = 32.; //fattore di scala
   printf("\nInserisci la temperatura in gradi Fahrenheit:\n");
   scanf("%f",&tf);
   
   tc=(tf-offset)*conv;
   printf("\nLa temperatura convertita in gradi Celsius e':%f\n",tc);
   
   system("PAUSE");

}
