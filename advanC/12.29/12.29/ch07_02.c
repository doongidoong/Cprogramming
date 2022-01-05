#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int arr[10];
	int rand1;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		rand1 = rand();
		arr[i] = (rand1 % 10) + 1;
		printf("%2d : ", arr[i]);
		for (int j = 0; j < arr[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
	

	return 0;
}