#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sumBetween(int, int);
int main() {
	int a, b;
	printf("Enter two integer : ");
	scanf("%d %d", &a, &b);
	printf("The sum between two integer is %d ", sumBetween(a, b));
	return 0;
}

int sumBetween(int a, int b) {
	int n_sum=0;
	int temp;
	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	}
	for (int i = a; i < b + 1; i++) {
		n_sum += i;
	}
	return n_sum;
}