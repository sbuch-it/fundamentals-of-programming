/* Sviluppare un programma di gestione di una rubrica telefonica che memorizza 
un massimo di 10 contatti, ciascuno dei quali si compone di nome, cognome e 
numero di telefono. La rubrica deve essere memorizzata su file e letta da file.

In questo ordine, il programma deve:
1) leggere da file la rubrica esistente
2) stampare a video tale rubrica (file: “rubrica.dat”).
3) fare in modo che l’utente possa aggiungere un nuovo contatto o cancellarne 
   uno esistente.
4) stampare a video la rubrica risultante 
5) aggiornare il file rubrica (“rubrica.dat”) con le nuove modifiche e terminare
*/
#include <stdio.h>

#define MAX_CONTATTI 10

// struttura che descrive un singolo contatto
typedef struct {
    char nome[20];
    char cognome[30];
    int telefono;
} contatto;

// lettura della rubrica da file (e memorizzazione nell'array "rubrica[]")
int carica_file_rubrica(contatto rubrica[]);
// stampa dell'array "rubrica[]"
void stampa_rubrica(contatto rubrica[], int num_contatti);
// aggiunta o rimozione di un elemento dall'array "rubrica[]"
int inserisci_o_modifica(contatto rubrica[], int num_contatti);
// scrittura su file del contenuto dell'array "rubrica[]"
void aggiorna_file_rubrica(contatto rubrica[], int num_contatti);


int main()
{
    contatto rubrica[MAX_CONTATTI];
    int num_contatti;  
    
    printf("Rubrica Telefonica\n");
    
    // (1) caricamento rubrica da file
    num_contatti = carica_file_rubrica(rubrica);
    // (2) stampa della rubrica a video
    stampa_rubrica(rubrica, num_contatti);
    // (3) inserimento o rimozione di un contatto
    num_contatti = inserisci_o_modifica(rubrica, num_contatti);
    // (4) stampa della rubrica risultante
    stampa_rubrica(rubrica, num_contatti);
    // (5) aggiornamento del file rubrica
    aggiorna_file_rubrica(rubrica, num_contatti);    
    
    getchar();
    getchar();
    return 0;
}

// lettura della rubrica da file (e memorizzazione nell'array "rubrica[]")
int carica_file_rubrica(contatto rubrica[])
{
    FILE *f;
    int num_contatti;
     
    f = fopen("rubrica.dat", "rb"); 
     
    if (f == NULL) { // se la rubrica non è mai stata creata...
       f = fopen("rubrica.dat", "wb+");  
       
       if (f == NULL) {        
          printf("Errore di accesso al file rubrica.\n");
          return 0;
       }
    }
     
    num_contatti = fread(rubrica, sizeof(contatto), MAX_CONTATTI, f);
    fclose(f);
    
    return num_contatti;
}

// stampa dell'array "rubrica[]"
void stampa_rubrica(contatto rubrica[], int num_contatti)
{
    int i;
    
    if (num_contatti == 0)
       printf("La rubrica e' attualmente vuota.\n");    
    else {
       for (i=0; i<num_contatti; i++) {
          printf("Contatto %d: ", i);
          printf("[%s %s, ", rubrica[i].nome, rubrica[i].cognome);
          printf("tel: %d]\n", rubrica[i].telefono);
       }
    }
}

// aggiunta o rimozione di un elemento dall'array "rubrica[]"
int inserisci_o_modifica(contatto rubrica[], int num_contatti)
{
    char c;
    int i,n;
    
    do {
       printf("Vuoi (A)ggiungere o (C)ancellare un contatto?\n");
       c = getchar();
       fflush(stdin);
    } while (c != 'a' && c != 'A' && c != 'c' && c != 'C');
    
    switch (c) {
           
       case 'a':
       case 'A':
          if (num_contatti == MAX_CONTATTI) {
             printf("La rubrica e' piena!\n");
             break;
          }
          printf("Nome: ");
          scanf("%s", rubrica[num_contatti].nome);
          printf("Cognome: ");
          scanf("%s", rubrica[num_contatti].cognome);
          printf("Telefono: ");
          scanf("%d", &(rubrica[num_contatti].telefono));             
          num_contatti++;
          break;
          
       case 'c':
       case 'C':
          if (num_contatti == 0) {
             printf("La rubrica e' vuota!\n");
             break;
          }            
          do {
             printf("Posizione del contatto da rimuovere?");
             scanf("%d", &n);
          } while (n>=num_contatti);
          
          for (i=n; i<num_contatti-1; i++) 
             rubrica[i]=rubrica[i+1]; 
          num_contatti--;                      
          break;
    }
    
    return num_contatti;
}

// scrittura su file del contenuto dell'array "rubrica[]"
void aggiorna_file_rubrica(contatto rubrica[], int num_contatti)
{
    FILE *f;
    int num_scritti;
     
    f = fopen("rubrica.dat", "wb");
     
    if (f == NULL) {
       printf("Errore di accesso al file rubrica.\n");
       return;
    }
     
    num_scritti = fwrite(rubrica, sizeof(contatto), num_contatti, f);
    
    if (num_scritti != num_contatti) {
       printf("Errore di scrittura.\n");                
    }
    
    fclose(f);    
}
