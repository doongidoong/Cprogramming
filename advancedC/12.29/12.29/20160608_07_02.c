#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 3
void inputMtx(int m[][SIZE], char mName);
void printMtx(int m[][SIZE]);
void addMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]);
void subMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]);
void mulMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]);
int main() {
	int m1[SIZE][SIZE] = {0};
	int m2[SIZE][SIZE] = {0};
	int R[SIZE][SIZE] = {0};
	inputMtx(m1, 'A');
	inputMtx(m2, 'B');
	printf("**************** Matrix A:\n");
	printMtx(m1);
	printf("**************** Matrix B:\n");
	printMtx(m2);
	printf("**************** Matrix A+B:\n");
	addMtx(m1, m2, R);
	printMtx(R);
	printf("**************** Matrix A-B:\n");
	subMtx(m1, m2, R);
	printMtx(R);
	printf("**************** Matrix A*B:\n");
	mulMtx(m1, m2, R);
	printMtx(R);
	return 0;
}

void inputMtx(int m[][SIZE], char mName) {
	printf("**************** inputing Matrix %c:\n", mName);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("Enter element of %c Matrix : [%d][%d] : ", mName, i, j);
			scanf("%d", &m[i][j]);
		}
	}
}
void printMtx(int m[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf(" %2d", m[i][j]);
		}
		printf("\n");
	}
}
void addMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			R[i][j] = A[i][j] + B[i][j];
		}
	}
}
void subMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			R[i][j] = A[i][j] - B[i][j];
		}
	}
}
void mulMtx(int A[][SIZE], int B[][SIZE], int R[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			R[i][j] = (A[i][0] * B[0][j]) + (A[i][1] * B[1][j]) + (A[i][2] * B[2][j]);
		}
	}
}