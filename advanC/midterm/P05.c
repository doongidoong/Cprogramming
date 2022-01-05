#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Fibonachi(int a1, int a2, int count) {
	if (count) {
		printf("%d ", a1);
		Fibonachi(a2, a2 + a1 , count-1);
		return 0;
	}
	else {
		return 0;
			}

}

int main() {
	int a1 = 0;
	int a2 = 1;
	int n;
	scanf("%d", &n);
	Fibonachi(0, 1, n);

	
}
