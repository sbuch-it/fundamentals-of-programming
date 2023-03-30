/* Scrivere il programma che calcola il massimo comun divisore di due interi con
 l’algoritmo di Euclide, strutturandolo in modo che il calcolo sia fatto in una
 apposita funzione */
#include <stdio.h>

// prototipo
int mcd(int, int);

int main() 
{
    int n1,n2;
    
    printf("Inserisci due numeri interi...\n");
    scanf("%d",&n1);
    scanf("%d",&n2); 
    printf("Il massimo comun divisore e' %d\n",mcd(n1,n2)); // il calcolo viene effettuato qui!
    
    getchar();  
    getchar();
    return 0;
}

/* Questa funzione calcola il MCD tra due interi */
int mcd(int a, int b) 
{ 
   int t; 
   while (b != 0)
   { 
      t = b; 
      b = a % b; 
      a = t; 
   } 
   return a; 
}
