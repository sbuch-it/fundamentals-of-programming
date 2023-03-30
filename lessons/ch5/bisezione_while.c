/*
  Metodo di bisezione per il calcolo degli zeri 
  di una funzione f in un intervallo (a,b) con precondizione f(a)*f(b)<0.
  In questa realizzazione f(x)=cos(x). Versione while.
*/

#include <math.h>
#include <stdio.h>

#define EPSILON 1.e-5

main() {
  double a = 0., b = M_PI, c;
 // double a = 1.570801, b = 1.570803, c;
  double delta = fabs(a - b);
  int i = 1;//conta il numero di iterazioni
  printf("Questo programma trova la soluzione "
         "dell'equazione cos(x)=0 in (0, PI)\n");
   c=a;     
  while (delta > EPSILON){
    double p;
    c = 0.5 * (a + b); //sarebbe meglio scrivere: a+0.5*(b-a)
    p = cos(a) * cos(c);
    if (p > 0.) {
      a = c;
    } else if (p < 0.) {
      b = c;
    } else { 
      a = b = c; /* soluzione esatta */
    }
    printf("Iterazione n. %d: x = %f\n", i++, c);
    delta = fabs(a - b);
  }
  
  printf("La soluzione trovata vale: %f\n", c);
  printf("La soluzione vera vale   : %f\n", 0.5 * M_PI);
  printf("La differenza vale       : %e\n", 
  fabs(0.5 * M_PI - c));
   
}
