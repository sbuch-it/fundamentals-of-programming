/*
implementazione che utilizza la valutazione di espressioni miste (logiche e aritmetiche)
*/
#include <stdio.h>

int main() {

	double a, b, c;

	printf("Inserire i 3 lati: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	double area1, area2, area3, area;//variabili per memorizzare aree "intermedie"
	
	/*nota: una sola tra area1,area2,area3 e' diversa da zero*/
	area1 = ((a>b)*(a>c))*(b*c)/2; //se a e' l'ipotenuta, altrimenti area1 e' zero
	area2 = ((b>a)*(b>c))*(a*c)/2; //se b e' l'ipotenuta, altrimenti area2 e' zero
	area3 = ((c>a)*(c>b))*(a*b)/2; //se c e' l'ipotenuta, altrimenti area3 e' zero
	
	area = area1 + area2 + area3;
	
	/*controllo che il triangolo sia rettangolo; se lo e' l'area e'
	calcolata correttamente*/
	area *= ((a*a==b*b+c*c)||(b*b==a*a+c*c)||(c*c==a*a+b*b));
	if (area)
		printf("Area: %lf", area);
	return 0;


}
