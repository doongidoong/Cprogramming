#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int i = 3, j = 5, * p = &i, * q = &j, * r;
	printf("%d \n", (p == &i));
	printf("*&p = %p\n", *&p);
	printf("&i = %p\n", &i);
	printf("**&p = %d\n", **&p);
	printf("7**p/*q+7 = %d\n", 7 * *p / *q + 7);
	*(r = &j) *= *p;
	printf("j = %d\n", *r);
	return 0;
}