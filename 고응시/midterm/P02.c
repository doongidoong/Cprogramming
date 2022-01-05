#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main() {

	int arr[100] = { 1, 1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 5, };
	int n;
	scanf("%d", &n);
	printf("%d", arr[n-1]);
	return 0;
}