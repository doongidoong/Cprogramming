#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 10, b = 4;
	double i, j;
	i = a;
	j = b;
	printf("%d\n", a / b);
	printf("%d\n", a / (int)j);
	printf("%lf\n", a / j);
	printf("%d\n", (int)(i/ b));
	printf("%lf\n", i / j);

	return 0;
}