#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
	int count;
	int* mostOccurData;
} Data_Info;
Data_Info Find_num(int* num);
int main() {
	srand((unsigned)time(NULL));
	int* num = (int*)malloc(sizeof(int)*10);
	for (int i = 0; i < 10; i++) {
		num[i] = rand() % 20 + 1;
	}
	Data_Info a = Find_num(num);
	FILE* fp = fopen("oufF_20160608_01.txt", "w");
	fprintf(fp, "DataList : ");
	for (int i = 0; i < 10; i++) {
		fprintf(fp, "%d", num[i]);
		if (i == 9) {
			fprintf(fp, "\n", num[i]);
			break;
		}
		fprintf(fp, ", ");
	}
	fprintf(fp, "The number that occured the most frequently : ");
	int i = 0;
	while(a.count>i){
		fprintf(fp, "%d", a.mostOccurData[i]);
		i++;
		if (a.count==i) break;
		fprintf(fp, ", ");
	}
	fclose(fp);
	free(a.mostOccurData);
}

Data_Info Find_num(int* num) {
	Data_Info a;
	int arr[21] = { 0 };
	for (int i = 0; i < 10; i++) {
		arr[num[i]] += 1;
	}
	int max = 0;
	for (int j = 1; j < 21; j++) {
		if (max < arr[j]) max = arr[j];
	}

	a.mostOccurData = (int*)malloc(sizeof(int)*10);
	int size = 0;
	for (int j = 1; j < 21; j++) {
		if (arr[j] == max) {
			a.mostOccurData[size] = j;
			size++;
		}
	}
	a.count = size;
	return a;
}