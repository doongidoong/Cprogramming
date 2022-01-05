#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

void mulMatrix(int(*A)[3], int SIZE, int(*B)[4], int(*R)[4]);

int main() {
	int A[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int B[3][4] = { 11, 12, 13, 14, 21, 22, 23, 24, 31, 32, 33, 34 };
	int R[3][4] = {0};
	mulMatrix((A), sizeof(A[0]) / sizeof(int), (B), (R));
	printf("*********** Matrix A * B **********\n");
	for (int i = 0; i < sizeof(R) / sizeof(R[0]); i++) {
		for (int j = 0; j < sizeof(R[0]) / sizeof(int); j++) {
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}
	return 0;
}


void mulMatrix(int(*A)[3], int SIZE, int(*B)[4], int(*R)[4]) {
	int bsize = sizeof(B[0]) / sizeof(int);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < bsize; j++) {
			for (int k = 0; k < SIZE; k++) {
				R[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}