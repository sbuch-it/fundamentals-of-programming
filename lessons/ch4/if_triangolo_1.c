/* if annidati (innestati) */
#include <stdio.h>

int main(void){
    float  a,b,c;
    
    printf("Inserisci il primo lato:");
    scanf("%f", &a);
    printf("Inserisci il secondo lato:");
    scanf("%f", &b);
    printf("Inserisci il terzo lato:");
    scanf("%f", &c);
    
    if (a==b)
    {
       if (b==c)
       {
          printf("Triangolo equilatero");
       }
       else
       {
          printf("Triangolo isoscele");
       }
    }
    else
    {
       if (b==c)
       {
          printf("Triangolo isoscele");  
       }
       else
       {
          if(a==c)
          {
               printf("Triangolo isoscele");
          }
          else
          {
               printf("Triangolo scaleno"); 
          }
       }
    }
                  
    getchar();
    getchar();
    return 0;
}
