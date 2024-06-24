/* 
questo programma calcola le coordinate x,y di un peso
lanciato ad angolo theta espresso in gradi con l'asse x, e v iniziale
v0. Tutte le grandezze vanno considerate nel sistema MKS
*/

#include <stdio.h>
#include <math.h>

#define G 9.82
#define PI 3.14159265


main() {
  double t = 0;          /* tempo */         
  double theta;          /* angolo di lancio in gradi*/
  double v0, v0x, v0y;   /* v iniziale e sue componenti  */
  double xt, yt;		/*coordinate del peso al tempo t*/
  
  const double conv=PI/180;  /*fattore di conversione da radianti in gradi */

/*Acquisizione dati*/
  printf("Inserisci l'angolo di lancio in gradi: ");
  scanf("%lf", &theta);
  printf("\nInserisci la velocita' iniziale in m/sec: ");
  scanf("%lf", &v0);
  printf("\nInserisci il valore del tempo t in sec: ");
  scanf("%lf", &t);
  
/* Calcola le componenti di v */
  v0x = v0 * cos(theta*conv);
  v0y = v0 * sin(theta*conv);

/* ora calcola le coordinate */
  xt = v0x * t;
  yt = v0y * t - 0.5 * G * pow(t, 2.0);
  
  /*visualizza i risultati*/
  printf("\nLe coordinate al tempo %f sono x = %f, y = %f\n"
  , t, xt, yt);
  
}
