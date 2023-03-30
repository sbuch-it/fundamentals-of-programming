/* puntatori */
#include <stdio.h>

int main() {
    int n;
    int *p=NULL;
    int *z=NULL;
        
    printf("Inserisci un intero: ");
    scanf("%d", &n);
    printf("\n0) Valore della variabile n = %d\n", n);
    printf("   Indirizzo della variabile n = %d\n", &n);    
    getchar();
    getchar();
    
    // si assegna l'indirizzo puntato 
    p = &n;
    printf("1) Il puntatore p e' stato fatto puntare all'indirizzo di n...\n");
    printf("   Valore della locazione puntata da p = %d\n", *p);
    printf("   Indirizzo della variabile p = %d\n", &p);
    printf("   Indirizzo della variabile puntata da p = %d\n", p);    
    getchar();
    
    // variazione della variabile n tramite il puntatore
    *p = 100;
    printf("2) Il valore della locazione puntata da p e' stato impostato a 100...\n");
    printf("   Valore della variabile n = %d\n", n);
    getchar();
      
    // si fanno puntare z e p allo stesso indirizzo
    z = p;
    printf("3) Il puntatore z e' stato uguagliato a p...\n");
    printf("   Valore della locazione puntata da z = %d\n", *z);
    printf("   Indirizzo della variabile z = %d\n", &z);
    printf("   Indirizzo della variabile puntata da z = %d\n", z);    
    getchar();
    
    // incremento del puntatore (+1 => +4)
    p++;
    printf("4) Il puntatore p e' stato incrementato di 1...\n");
    printf("   Valore della locazione puntata da p = %d\n", *p);
    printf("   Indirizzo della variabile p = %d\n", &p);
    printf("   Indirizzo della variabile puntata da p = %d\n", p);    
    getchar();
    
    return 0;
}
