#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int input_Set(int*, char);
int intersection(int*, int, int*, int, int*);
int difference(int*, int, int*, int, int*);
void print_Set(int*, int);

int input_Set(int*, char);
int main() {
	int A[20];
	int B[20];
	int inter[20];
	int diff[20];

	printf("*********** Inputing Set A *****************\n");
	int asize= input_Set(A, 'A');
	printf("\n*********** Inputing Set B *****************\n");
	int bsize = input_Set(B, 'B');
	printf("\n*********** Set A **************************\n");
	print_Set(A, asize);
	printf("\n*********** Set B **************************\n");
	print_Set(B, bsize);
	printf("\n*********** Intersection(A, B) *************\n");
	int intersize = intersection(A, asize, B, bsize, inter);
	print_Set(inter, intersize);
	printf("\n*********** Difference(A, B) ****************\n");
	int diffsize = difference(A, asize, B, bsize, diff);
	print_Set(diff, diffsize);
	return 0;
}


int input_Set(int* arr, char c){
	int index = 0;
	int count = 0;
	while (1) {
		printf("Enter element of %c Set [%d] : ", c, index);
		scanf("%d", (arr + index));
		if (*(arr + index)<=0) break;
		count++;
		index++;
	}
	return count;
}

void print_Set(int arr[], int a) {
	printf("{");
	for (int i = 0; i < a; i++) {
		printf(" %d", arr[i]);
		if (i == (a - 1)) break;
		printf(",");

	}
	printf("}");

}
int intersection(int *arr, int a, int *arr2, int a2, int *R) { //교집합 길이 반환
	int count = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a2; j++) {
			if (*(arr+i) == *(arr2+j)) {
				*(R+count) = *(arr+i);
				count++;
			}
		}
	}
	return count;
}

int difference(int* arr, int a, int* arr2, int a2, int* R) { //차집합 길이 반환
	int count = 0;
	int check = 0; //같은게 하나라도 있을 경우 추가X
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a2; j++) {
			if (*(arr + i) == *(arr2 + j)) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			*(R + count) = *(arr + i);
			count++;
		}
		check = 0;
	}
	return count;
}