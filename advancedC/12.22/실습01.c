#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char a = 65;
	short b = 12345;
	int c = 123456789;
	long long d = -12345678901234;

	float f = 3.141592845f;
	double ff = 3.141592845f;

	double e = 31415.92e-4;

	printf("%c, %d \n",a,a);
	printf("%d, %d %lld \n", b, c, d);
	printf("%f, %lf, %e \n", f, ff, ff);
	printf("%lf, %e \n", e, e);

	return 0;
}