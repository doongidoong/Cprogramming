#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int intersection(int arr[], int a, int arr2[], int a2, int R[]);
void print_Set(int[], int);
int main() {
	int A[] = {	1,3,5,7,9,10};
	int B[] = {3,5,8,9};
	printf("*********** Set A **************************\n");
	int Asize = sizeof(A) / 4;
	int Bsize = sizeof(B) / 4;
	print_Set(A, Asize);
	printf("\n*********** Set B **************************\n");

	print_Set(B, Bsize);
	int R[6];
	printf("\n*********** intersection(A, B) *************\n");
	int answer = intersection(A, Asize, B, Bsize, R);
	
	print_Set(R, answer);

}

void print_Set(int arr[], int a){
	printf("{");
	for (int i = 0; i < a; i++) {
		printf(" %d", arr[i]);
		if (i == (a - 1)) break;
		printf(",");

	}
	printf("}");
	
}
int intersection(int arr[], int a, int arr2[], int a2, int R[]) {
	int count = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a2; j++) {
			if (arr[i] == arr2[j]) {
				R[count] = arr[i];
				count++;
			}
		}
	}
	return count;
}