/* Scrivere il programma che legge un carattere da tastiera e riconosce se
  vengono inseriti ‘a’, o ’b’, o ’c’ */
#include <stdio.h>

int main()
{
    char c;
    
    printf("Inserisci un carattere:\n");
    scanf("%c",&c);                  
    
    if (c=='a' || c=='b' || c=='c')
        printf("Hai inserito uno dei caratteri noti, ossia %c\n",c);
    else
        printf("Non hai inserito uno dei caratteri noti!\n");
           
    getchar();
    getchar();
    return 0;
}
