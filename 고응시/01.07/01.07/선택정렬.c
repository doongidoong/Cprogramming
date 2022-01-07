#include <stdio.h>
#include <limits.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

}

void Bub_sort(int* arr,int n1) {
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1 - i - 1; j++) {
			if(arr[j]>arr[j+1]) swap(&arr[j],&arr[j+1]);
		}
	}
}
void Ins_sort(int* arr, int n1) {
	for (int i = 0; i < n1-1; i++) {
		for (int j = i+1; j < n1; j++) {
			if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);
		}
	}


}


void Sel_sort(int* arr, int size) {	
	int min;
	int index = -1;
	for (int i = 0; i < size; i++) {
		min = INT_MAX;
		for (int j = i + 1; j < size; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
			if (arr[i] > arr[index])swap(&arr[i], &arr[index]);

		}
	}
	printf("Selection Sorting is done!!\n");
}


int main() {
	int arr[] = {10,9,12, 8,7,23, 13, 6,5,4,3,2,101,22,25};
	int* p = arr;
	Bub_sort(p,15);
	
	for (int i = 0; i < 15; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}