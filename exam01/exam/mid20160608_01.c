#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int swap(int* a, int* b);

int main() {
	int arr[10];
	int rank[10];
	int arr2[10];
	srand((unsigned)time(NULL));
	int num;
	for (int i = 0; i < 10; i++) {
		num = rand() % 30 + 70;
		arr[i] = num;
		arr2[i] = num;
	}
	
	int r = 0;
	while (r< 10) {
		int index = 0;
		int maxn = 0;
		for (int i = 0; i < 10; i++) {
			if (maxn < arr2[i]) {
				maxn = arr2[i];
				index = i;
			}
		}
		arr2[index] = 0;
		rank[index] = r + 1;
		for (int i = 0; i < 10; i++) {
			if ((index!=i)&&(arr[index]>=0)&&(arr[index] == arr2[i])) {
				arr2[i] = 0;
				rank[i] = r + 1;
				r++;

			}			
		}
		r++;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d student(%d) : %d ranking \n", i, arr[i], rank[i]);
	}
	return 0;
}

int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

