#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int x,y;
	printf("Enter variable x : ");
	scanf("%d", &x);
	printf("Enter variable y : ");
	scanf("%d", &y);
	printf("Result of expression 1 is %.2f \n", pow(x, 2) + pow(y, 2)); //  X^2 + y^2
	printf("Result of expression 2 is %.2f\n", pow(x+y, 2)); // (X+Y)^2
	printf("Result of expression 3 is %.2f\n", pow(fabs(x+y), 2) ); // abs(X+Y)^2
	printf("Result of expression 4 is %.2f\n", sqrt(pow(x, 2) + pow(y, 2))); // sqrt(X^2 + y^2)
	system("pause");


	return 0;
}