/* typedef, strutture, stringhe */
#include <stdio.h>

int main() {
    // typedef
    typedef int tipointero;
    typedef int vettoredicinqueinteri[5];
    typedef char stringa[20]; // tipo di dato "stringa"
    
    // struttura
    struct nomestruttura { // "nomestruttura" può essere omesso, ma è conveniente usarlo per riusare il template
		    int numero;	    
            char testo[30];
    } struttura_numtesto; // "struttura_numtesto" è una variabile di tipo "struct nomestruttura"
    
    // riuso del template (tag)
    struct nomestruttura altra_struttura_numtesto; // non verrà usata nel seguito...
                   
    // typedef su struttura
    typedef struct appunto { // "appunto" può essere omesso (siccome adesso definisco un nuovo tipo)
            int ore; 
		    int min; 	
		    int sec; 
		    tipointero identificativo;
		    char nome[11];
		    stringa note;	    
    } struttura_appunto; // "struttura_appunto" adesso è il nome di un nuovo TIPO di dato (non è una variabile)!!!
    
    // utilizzo del nuovo tipo
    struttura_appunto var1;	  
      
    // riuso del template...è ancora possibile, ma scomodo
    struct appunto a; // non verrà usata nel seguito...
    
    printf("Memoriazzazione di un nuovo appunto...\n");
    printf("Ore?\n");
    scanf("%d", &var1.ore);    
    printf("Minuti?\n");
    scanf("%d", &var1.min);    
    printf("Secondi?\n");
    scanf("%d", &var1.sec);    
    printf("Identificativo?\n");
    scanf("%d", &var1.identificativo);
    printf("Nome? (max 10 caratteri)\n");
    scanf("%s", var1.nome);
    printf("Note? (max 20 caratteri)\n");
    scanf("%s", var1.note);
    
    printf("Nome: %s, Ore %d, Min %d, Sec %d, ID %d, Note: %s\n", var1.nome, var1.ore, var1.min, var1.sec, var1.identificativo, var1.note);           
    
    // copia di dati tra strutture diverse
    struttura_numtesto.numero = var1.identificativo;
    strcpy(struttura_numtesto.testo, var1.nome);
            
    printf("Dati copiati: %s, %d\n", struttura_numtesto.testo, struttura_numtesto.numero);
    
    fflush(stdin);
    getchar();    
    return 0;        
}
