#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 7
#define K 60000000

int main(){
	unsigned int frequency[SIZE]={0};
	unsigned int roll,face;
	
	srand(time(NULL));//seme per il generatore di numeri casuali
	
	//lancia il dado 60000000 volte
	for(roll=1;roll<=K;++roll){
		face=1+rand()%6;
		++frequency[face-1];
	}
	
	printf("%s%s\n","Face","Frequency");
	
	for(face=0;face<SIZE;++face){
		printf("%d %d\n",face+1,frequency[face]);
	}
}
