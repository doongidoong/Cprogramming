#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>
int Max(int* data, int size);
int Min(int* data, int size);
void Std(int* data, int size);
void pr_arr(int* arr, int n1);
void swap(int* a, int* b);
void Sel_sort(int* arr, int size);
void Ins_sort(int* arr, int size);
void Bub_sort(int* arr, int size);
int Seq_search(int* arr, int size);
int Bin_search(int* arr, int size);
int main() {
	int n1, n2;
	printf("Enter the number of elements in the array : ");
	scanf("%d", &n1);
	printf("Enter the maximum possible values as the elements of the array : ");
	scanf("%d", &n2);
	int* arr = (int*)malloc(n1 * sizeof(int));
	int* checkarr = (int*)calloc(n2,sizeof(int));
	srand((unsigned)time(NULL));
	int n3;
	int cnt = 0;
	while(cnt<n1){
		n3= rand()%n2;
		if(checkarr[n3]==0){
			arr[cnt] = n3;
			cnt++;
			checkarr[n3] = 1;
		}

	}
	FILE *fp = fopen("in_12_20160608.txt","w");
	cnt = 0;
	while (cnt < n1) {
		fprintf(fp, "%5d", arr[cnt]);
		cnt++;
		if ((cnt) % 5 == 0) {
			fprintf(fp,"\n");
		}
	}
	fclose(fp);

	free(checkarr);
	
	int instruct;
	int check = 0;
	FILE* fp_r = fopen("in_12_20160608.txt", "r");
	while (1) {
		printf("\n*********************************************** ");
		printf("\n**** List of array instructions *****\n ");
		printf("\t1: Read data from file\n");
		printf("\t2: Sequential Search\n");
		printf("\t3: Binary Search\n");
		printf("\t4: Selection Sort\n");
		printf("\t5: Bubble Sort\n");
		printf("\t6: Standard deviation of array\n");
		printf("\t7: Min/Max elements of array\n");
		printf("\t8: Print array\n");
		printf("\t0: Program Exit\n");
		printf("Choose the instruct number : ");
		scanf("%d", &instruct);
		if (instruct == 0) {
			break;
		}
		if (instruct == 1) {
			if (check == 1) continue;
			cnt = 0;
			arr = (int*)malloc(n1 * sizeof(int));
			while (n1 > cnt) {
				fscanf(fp_r, "%d", &arr[cnt]);
				cnt++;
			}
			check = 1;
			continue;
		}
		if (check < 1) {
			printf("Read data from input file, choose 1!!\n");
			continue;
		}
		if (instruct == 2) { 
			Seq_search(arr, n1); 
			continue;
		}
		if( instruct == 3) {
			if (check < 2) {
				printf("Sort first before Binary Search!!!!\n");
				continue;
			}
			Bin_search(arr, n1);
			continue;
		}
		if (instruct == 4) {
			Sel_sort(arr, n1);
			check = 2;
			continue;
		}
		if (instruct == 5){
			Bub_sort(arr, n1);
			check = 2;
			continue;
		}
		if (instruct == 6) { 
			Std(arr, n1); 
			continue;
		}
		if (instruct == 7) {
			printf("Min data : %d, Max data : %d\n", Min(arr, n1), Max(arr, n1));
			continue;
		}
		if (instruct == 8) {
			pr_arr(arr, n1);
			continue;
		}
		printf("Please enter correct Instruction!!!\n");
	}
	free(arr);
	
	fclose(fp_r);
	return 0;
}



void pr_arr(int* arr, int n1) {
	int cnt = 0;
	printf("Array : %d elements", n1);
	while (cnt < n1) {
		if ((cnt) % 5 == 0) {
			printf("\n");
		}
		printf("%5d", arr[cnt]);
		cnt++;
		
	}
	printf("\n");

}

int Seq_search(int *arr, int size) {
	int num;
	printf("Enter data to find : ");
	scanf("%d", &num);
	for (int i = 0; i < size; i++) {
		if (num == arr[i]) {
			printf("%d is located in %d \n", num, i);
			return 0;
		}
	}
	printf("%d was not found\n",num);
	return 0;

}
int Bin_search(int* arr, int size) {
	int num;
	printf("Enter data to find : ");
	scanf("%d", &num);
	int lt = 0;
	int rt = size;
	int mid;
	while (lt <= rt) {
		mid = (lt + rt) / 2;
		if (arr[mid] == num) {
			printf("%d is located in %d \n", num, mid);
			return 0;
		}
		else if(arr[mid] > num) {
			rt = mid - 1;
		}
		else {
			lt = mid + 1;
		}
	}
	printf("%d was not found\n", num);
	return 0;

}
int Min(int* data, int size) {
	int min = INT_MAX;
	for (int i = 0; i < size; i++) {
		if (min > data[i]) min = data[i];
	}
	return min;
}
int Max(int* data, int size) {
	int max = INT_MIN;
	for (int i = 0; i < size; i++) {
		if (max < data[i]) max = data[i];
	}
	return max;
}
void Std(int *data, int size) {
	double sum = 0.0;
	double mean = 0, std = 0.0;
	int i;
	for (i = 0; i < size ; i++) {
		sum += data[i];
	}
	mean = sum / size;
	for (i = 0; i < size; i++)
		std += pow(data[i] - mean, 2);
	printf("Standard Deviation : %.2f\n",sqrt(std / size));
}


void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

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

void Bub_sort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
		}
	}
	printf("Bubble Sorting is done!!\n");
}
void Ins_sort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);
		}
	}
	printf("Insertion Sorting is done!!\n");

}