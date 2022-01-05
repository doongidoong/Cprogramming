#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isprime(int a);
int main() {
	int arr[10];
	int arr2[10] = {0};
	int count = 0;
	int num ;
	for (int i = 0; i < 10; i++) {
		num = 0;
		printf("Enter %d positive int data ( > 1) : ",i+1);
		scanf("%d", (&arr[i]));
		num = isprime(arr[i]);
		if (isprime(arr[i])) {
			arr2[i] = num;
			count++;
		}
	}	
	printf("\n***** %d prime numbers ******\n", count);
	for (int i = 0; i < 10; i++) {
		if (arr2[i]>0) printf(" %2d",arr2[i]);
	}

	return 0;
}

int isprime(int a) {
	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return a;
}