/*codifica un testo inserito da tastiera usando un cifrario di Vigenere.
realizzare una funzione che trasforma un carattere in un altro della base chiave. 
*/
#include <stdio.h>


#define MAX_STRING 300
#define N_LETTERE 26

/*dichiarazione della funzione*/
char cesare(char,char);

int main() {
   char c, line[MAX_STRING],line_cod[MAX_STRING]; //memorizza la frase digitata da tastiera
   char verme[]="VERME";//memorizza il verme
   int i=0,j=0,passo;
   int length=0;;
   int countchar;
   
   while(verme[i]!='\0'){
		length++;
		i++;
   }
   
   /*Acquisizione dati*/
   printf("\n Inserire la frase da codificare "
   " (il tasto INVIO per terminare l'input, max 255 caratteri): ");
   i=0;
   while ((c = getchar()) != '\n' && i < MAX_STRING) {
      line[i++] = c;
   }
   line[i]='\0';
   /*visualizza frase da codificare*/
   i=0;
   printf("\n Frase in chiaro:\n");
   //printf("%s\n",line);
   while((c=line[i])!='\0'){
		printf("%c",c);
		i++;
   }
   
   i=0;
   countchar=0;
   while(line[i]!='\0'){
		if(line[i]!=' '){
			passo = countchar%length;
			line_cod[i]=cesare(line[i],verme[passo]-'A');
			countchar++;
		}
		else line_cod[i]=line[i];
		i++;
		}
		line_cod[i]='\0';
   
   /*visualizza il testo cifrato*/
   i=0;
   printf("\n Frase codificata:\n");
   while((c=line_cod[i])!='\0'){
		printf("%c",c);
		i++;
   }
   return 0;
}

/*definizione della funzione di codifica*/
char cesare(char ch,char offset){
	if(isalpha(ch)!=0){
		if(ch>='a'&& ch<='z')
			return((ch+offset-'a')%N_LETTERE+'a');
		else if(ch>='A'&& ch<='Z')
			return((ch+offset-'A')%N_LETTERE+'A');
		}
}
