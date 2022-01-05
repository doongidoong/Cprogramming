#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	float a ;
	double b;
	printf("Enter float num & double num : ");
	scanf("%f %lf", &a, &b);
	if(a == 0.2f)
		printf("a : equal\n");
	else
		printf("a : not equal\n");
	if (b == 0.2)
		printf("b : equal\n");
	else
		printf("a : not equal\n");

}