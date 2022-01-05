#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int a;
	int num1;
	int num2;
	printf("Enter a two-digit integer: ");
	scanf("%d", &a);
	num1 = a / 10;
	num2 = a % 10;
	printf("2 to %d times : %d", num1*num2, 1<< num1 * num2);



	return 0;
}