/*Iinserimento dati in un formato particolare con scanf*/
#include <stdio.h>
#define LEN 20

int main()
{
  char month[LEN];
  int day,year;
  int status=0;
  
  printf("Inserire una data nella forma 1 Aprile 2015\n");

  status=scanf("%d %s %d",&day, month,&year);
  
  printf("Il numero di valori inseriti e' %d\n",status);
  printf("Il mese inserito e' %s\n", month);
  printf("La data e':%d %s %d\n",day,month,year);
  
}
