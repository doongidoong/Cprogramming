#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Myfunc(int);
int main() {
	int i;
	for (i = 0; i < 3; i++) {
		Myfunc(i);
	}

	return 0;
}

void Myfunc(int n) {
	static int a = 1;
	int b = 1;
	printf("%d Myfunc() call: a= %d, b = %d\n", n + 1, a++, b++);

}