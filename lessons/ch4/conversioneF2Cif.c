/*Sara Brunetti
programma di conversione da gradi Fahrenheit a Celsius.
e viceversa
*/
#include <stdio.h>

main() {
   double tc, tf, conv;
   double const offset = 32.;
   
   char ch;
   puts("Inserisci 1 se vuoi convertire da Fahrenheit a Celsius, 2 altrimenti");
   scanf("%c",&ch);
   if(ch=='1'){
	   conv = 5. / 9.;
	   printf("Valore in gradi Fahrenheit= ");
	   scanf("%lf",&tf);
	   tc = (tf - offset) * conv;
	   printf("Valore in gradi celsius= %f\n",tc);
	}
	else{
	   conv = 9. / 5.;
	   printf("Valore in gradi celsius= ");
	   scanf("%lf",&tc);
	   tf = tc * conv + offset;
	   printf("Valore in gradi Fahrenheit= %f\n",tf);
	}
}
