#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10000
int main() {
	int arr[SIZE+1] = { 0 };
	double n = 0;
	int num2;
	scanf("%lf", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num2);
		arr[num2] += 1;
	}
	int k = 0;
	int num3 = 0;
	int i;
	for (int i = 0; i <= SIZE; i++) {
		if (arr[i] > 0) {
			for (int j = 0; j < arr[i]; j++)printf("%d \n", i);
		}
	}

	return 0;
}