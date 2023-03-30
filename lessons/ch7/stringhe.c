/* stringhe */
#include <stdio.h>
#include <string.h>


int main(void) {
    char nome1[20], nome2[20];
    char cognome1[20], cognome2[20];
    char nome3[] = "Pippo";
    char cognome3[] = "Pippesi";
    int lunghezza;
    
    printf("Inserisci il primo nome e cognome (max 20 caratteri): \n");
    scanf("%s", nome1);
    scanf("%s", cognome1);
    printf("Inserisci il secondo nome e cognome (max 20 caratteri): \n");
    scanf("%s", nome2); 
    scanf("%s", cognome2); 
    
    printf("\nLista dei nomi inseriti e di quelli gia' presenti:\n");
    printf("%s %s\n", nome1, cognome1); 
    printf("%s %s\n", nome2, cognome2); 
    printf("%s %s\n", nome3, cognome3); 
    
    // alterazioni di stringhe
    strcpy(nome1, nome2);  // copia nome2 su nome1  
    
    strncpy(cognome1, cognome3, 3); // copia 3 caratteri di cognome3 su cognome1
         
    strncpy(cognome2, cognome3, 3); // copia 3 caratteri di cognome3 su cognome2
    cognome2[3] = '\0'; // termina al carattere 3 congome2
    
    strcat(nome3, nome1); // appende in coda a nome3 il nome1
    
    printf("\nLista dopo alterazione di nomi e cognomi:\n");
    printf("%s %s\n", nome1, cognome1); 
    printf("%s %s\n", nome2, cognome2); 
    printf("%s %s\n", nome3, cognome3); 
    
    // lunghezze e confronti    
    lunghezza = strlen(nome3);    
    printf("\nIl nome 3 e' lungo %d\n", lunghezza);
    
    if (strcmp(nome1,nome2) == 0)
       printf("I primi due nomi sono uguali!\n");
    else
       printf("I primi due nomi sono diversi!\n");
              
   
    getchar();
    getchar();  
    
    return 0;
}
