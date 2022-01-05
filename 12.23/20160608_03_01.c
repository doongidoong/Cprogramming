#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {
	int a;
	int b;
	int temp;

	printf("Enter two int num :\n");
	scanf("%d %d",&a,&b);
	printf("************************************************************ \n");
	printf("Original value : a = %d, b = %d \n",a,b);
	temp = a;
	a = b;
	b = temp;
	printf("Exchagned value : a = %d, b= %d \n", a, b);
	printf("Sum : %d, Average %.2f",a+b,(a+b)/2.0);


}