#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	scanf("%d", &size);
	int **arr;
	arr = (int**)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++) {
		arr[i] = (int*)malloc(sizeof(int)*size);
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = i * size + j;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
	int i;
	int k;
	int c = 1;
	while(c<=size/2){
	i = c - 1;
	for (k = c - 1; k <= size - c; k++)printf(" %d", arr[i][k]);// 00 01 02 03 
	for (i = c; i <= size - c; i++)printf(" %d", arr[i][k - 1]); // 13 23 33

	for (k = size - c - 1; k >= c - 1; k--)printf(" %d", arr[i - 1][k]); // 32 31 30
	for (i = i- 2; i >= c ; i--)printf(" %d", arr[i][k + 1]); // 20 10 
	c++;
	}
	if (size % 2 != 0) {
		printf(" %d", arr[(c+1)/2][(c + 1) / 2]);
	}

	return 0;
}