/*ordina un array utilizzando la funzione bubblesort.
suddivide gli elementi pari e dispari in due vettori*/
#include<stdio.h>

/*void sortByParity(int data[], int odd[], int even[], int n);*/
void bubblesort(int data[], int n);


main(){
	int i;
	int buffer[5]={2,1,4,6,5};
	for(i=0;i<5;i++)
		printf("%d",buffer[i]);
	printf("\n");
	bubblesort(buffer,5);
	for(i=0;i<5;i++)
		printf("%d",buffer[i]);
	printf("\n");
}

void bubblesort(int data[], int n) {
  int i, temp, *pd;
  for (i = 0; i < n - 1; i++) {
    for (pd = data + n - 1; pd > data + i; pd--) {
      if (*(pd - 1) > *pd) {
			temp = *(pd - 1);
		    *(pd - 1) = *pd;
		    *pd = temp;
      }
    }
  }
}

void sortByParity(int data[], int odd[], int even[], int n) {
  int *pd, *pt_odd, *pt_even;
  pt_odd=odd;
  pt_even=even;
  bubblesort(data, n);
  for (pd = data; pd < data + n; pd++) {
    if (*pd % 2) {
      odd[*pt_odd] = *pd;
      pt_odd++;
    } else {
      even[*pt_even] = *pd;
      pt_even++;
    }
  }
}
