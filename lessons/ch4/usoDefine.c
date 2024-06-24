/*marzo 2017
Sara Brunetti
programma di conversione da gradi Fahrenheit a Celsius.
esempio di uso delle direttive #define TF2TC,#ifdef,#endif,#ifndef
*/
#include <stdio.h>
#include<stdlib.h>

//#define TF2TC 

main() {
   double tc, tf, conv;
  
   double const offset = 32.;
#ifdef TF2TC   
   conv = 5. / 9.;
   printf("Valore in gradi Fahrenheit= ");
   scanf("%lf",&tf);
   tc = (tf - offset) * conv;
   printf("Valore in gradi celsius= %f\n",tc);
#endif
#ifndef TF2TC
   conv = 9. / 5.;
   printf("Valore in gradi celsius= ");
   scanf("%lf",&tc);
   tf = tc * conv + offset;
   printf("Valore in gradi Fahrenheit= %f\n",tf);
#endif
system("PAUSE");
}
