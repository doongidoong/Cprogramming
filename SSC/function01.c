#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS


int swap(int* a, int* b);
int add_number(int* arr);
int max_number(int* arr);
int des_sort(int* arr);
int main() {
	int a;
	int b;
	int arr[10];
	int *par = arr;
	for (int i = 0; i < sizeof(arr)/4; i++) {
		scanf("%d",&arr[i]);
	}
	des_sort(arr);
	for (int i = 0; i < sizeof(arr) / 4; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}


int des_sort(int* arr) {
	int s = 0; 
	int e = 10;
	int maxn = 0;
	int temp = 0;
	while(s!=e){
		for (int i = s; i < e; i++) {
			if (arr[i] > maxn) {
				maxn = arr[i];
				temp = i;
			}
		}
		arr[temp] = arr[s];
		arr[s] = maxn;
		maxn = 0;
		s++;
	}
}


int max_number(int *arr) {
	int s = 0;
	for (int i = 0; i < 10; i++) {
		if (s < arr[i]) {
			s = arr[i];
		}
		printf("%d \n", s);
	}
	return s;
}


int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int add_number(int *arr) {
	for (int i = 0; i < 3;i++) {
		arr[i]++;
	}
	
}