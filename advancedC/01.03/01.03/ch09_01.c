#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() { 
	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int* p = arr;
	printf("************** Original Array **************\n");
	while (*p>=0) printf("%d ", *p++);
	p--;
	printf("\n************** Reversed Array **************\n");
	while (*p >= 0) printf("%d ", *p--);
	
	
	return 0; }