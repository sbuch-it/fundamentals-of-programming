#include <stdio.h>

char* inserisci()
{
      char m[100];
      int lunghezza;
      char *p;
      
      printf("Inserisci il messaggio da cifrare/decifrare...\n");
      scanf("%s", m);
      
      lunghezza = strlen(m);
      lunghezza++; // incremento di 1 perchè altrimenti la lunghezza non considera il carattere \0 di fine stringa!
      
      p = (char*)malloc(lunghezza * sizeof(char)); // riservo lo spazio minimo per contenere il messaggio inserito
      strcpy(p,m); // copio m in p
      p[lunghezza-1] = '\0'; // inserisco esplicitamente il carattere di fine stringa, perchè strcpy non lo considera
      
      return p;
}

char* cifra(char *msg, int chiave)
{
      int lunghezza;
      int i;
      char *msg_cifrato;
           
      lunghezza = strlen(msg); 
      printf("%d\n", lunghezza);  
      lunghezza++;
         
      msg_cifrato = (char*)malloc(lunghezza * sizeof(char));
      
      for (i=0; i<lunghezza-1; i++) {
          msg_cifrato[i] = ((int)msg[i] + chiave)%256; // ogni carattere è rappresentato con un intero tra 0 e 255 (compresi). L'operazione di modulo (%) mi garantisce che dopo aver addizionato la chiave mi trovo ancora in tale intervallo.
      }
      msg_cifrato[lunghezza-1] = '\0';
      
      return msg_cifrato;
}

char* decifra(char *msg, int chiave)
{
      return cifra(msg, -chiave); // decifrare è come cifrare con la chiave cambiata di segno!
}

void stampa(char *msg, char *msg_modificato)
{
     printf("Hai inserito: %s\n", msg);
     printf("Messaggio cifrato/decifrato: %s\n", msg_modificato);
}

int main()
{
    int chiave;
    char *messaggio;
    char *messaggio_modificato;
    char c;
    
    messaggio = inserisci();
    
    printf("Inserisci la chiave (intero positivo)...\n");
    scanf("%d", &chiave);    
    
    printf("Inserisci 'c' per cifrare, 'd' per decifrare...\n");
    getchar();
    scanf("%c", &c);
    switch (c) {
           case 'c':
                messaggio_modificato = cifra(messaggio, chiave);
                break;
           case 'd':
                messaggio_modificato = decifra(messaggio, chiave);                
                break;
           default:
                printf("Scelta non valida!\n");
                return 0;
                break;                        
    }  
    
    stampa(messaggio, messaggio_modificato);
    
    getchar(); getchar();
    return 0;
}
