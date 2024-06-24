#include <stdio.h>

void istruzioni()
{
     printf("Utilizzo del cifratore/decifratore di file:\n");
     printf("\ncifratura_file [azione] [fileinput] [password] [fileoutput]\n");
     printf("\n\t[azione]: {c,d} dove c->cifra e d->decifra.\n");     
     printf("\t[fileinput]: file da cifrare o decifrare.\n");
     printf("\t[password]: chiave di cifratura o decifratura.\n");     
     printf("\t[fileoutput]: file cifrato o decifrato.\n\n");     
}

int dimensione_file(char *filename)
{
     FILE *f;
     int dimensione;
     
     f = fopen(filename, "rb");
     if (f == NULL) {
           printf("Impossibile aprire: %s\n", filename);
           exit(1);
     }
     
     fseek(f, 0, SEEK_END);
     dimensione = ftell(f);
     fclose(f);
     
     return dimensione;    
}

char* carica_in_memoria(char *filename, int dimensione) 
{
     FILE* f;
     int byte_letti;
     char* file_in_memoria;
     
     f = fopen(filename, "rb");
     if (f == NULL) {
           printf("Impossibile aprire: %s\n", filename);
           exit(1);
     }
     
     file_in_memoria = (char *)malloc(dimensione);
     if (file_in_memoria == NULL) {
           printf("Impossibile riservare memoria per: %s\n", filename);
           exit(1);                         
     }
     
     byte_letti = fread(file_in_memoria, sizeof(char), dimensione, f);
     if (byte_letti != dimensione) {
           printf("Impossibile leggere correttamente: %s\n", filename);
           exit(1);                        
     }
     
     fclose(f);
     
     return file_in_memoria;
}

char* cifra(char *file_in_memoria, int dimensione, int chiave)
{
      char *file_in_memoria_2;
      int i;
      
      file_in_memoria_2 = (char *)malloc(dimensione);
      if (file_in_memoria_2 == NULL) {
            printf("Impossibile riservare la memoria necessaria\n");
            exit(1);                         
      }
      
      for (i = 0; i < dimensione; i++) {
          *(file_in_memoria_2+i) = (*(file_in_memoria+i) + chiave) % 256;
      }
      
      return file_in_memoria_2;
}

char* decifra(char *file_in_memoria, int dimensione, int chiave)
{
      return cifra(file_in_memoria, dimensione, -chiave);
}

void salva_su_file(char *file_in_memoria, int dimensione, char* filename)
{
     FILE *f;
     int i;
     int byte_scritti;
     
     f = fopen(filename, "wb+");
     if (f == NULL) {
           printf("Impossibile salvare: %s\n", filename);
           exit(1);
     }   
     
     byte_scritti = fwrite(file_in_memoria, sizeof(char), dimensione, f);
     if (byte_scritti != dimensione) {
           printf("Impossibile salvare correttamente: %s\n", filename);
           exit(1);                        
     }
     
     fclose(f);    
}

int main(int argc, char *argv[])
{
    char *in, *out;
    int psw, dim;
    char action;
    char *dati_in, *dati_out;
    
    if (argc != (1+4)) {
        istruzioni();
        return 0;
    }
    
    action = *argv[1];
    in = (char *)argv[2];
    psw = atoi(argv[3]);
    out = (char *)argv[4];
    
    if (psw <= 0) {
        printf("Password non valida.\n");
        return 0;
    }
    
    dim = dimensione_file(in);
    dati_in = carica_in_memoria(in, dim);
    
    switch(action) {
        case 'c':
             dati_out = cifra(dati_in, dim, psw);
             free(dati_in);
             break;
        case 'd':
             dati_out = decifra(dati_in, dim, psw);
             free(dati_in);
             break;
        default:
             printf("Azione non valida.\n");
             return 0;
             break;
    }
    
    salva_su_file(dati_out, dim, out);
    free(dati_out);

    return 0;
}
