/* if annidati (innestati), senza parentesi */
#include <stdio.h>

int main(void){
    float  a,b,c;
    
    printf("Inserisci il primo lato: ");
    scanf("%f", &a);
    printf("Inserisci il secondo lato: ");
    scanf("%f", &b);
    printf("Inserisci il terzo lato: ");
    scanf("%f", &c);
    
    if (a==b && b==c)
        printf("Triangolo equilatero");
    
    if ((a==b && b!=c) || (b==c && a!=b) || (a==c && c!=b))     
        printf("Triangolo isoscele");
    
    if (a!=b && b!=c && a!=c) 
        printf("Triangolo scaleno"); 
                  
    getchar();
    getchar();
    return 0;
}
