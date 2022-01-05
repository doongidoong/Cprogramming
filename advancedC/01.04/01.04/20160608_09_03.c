#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
void data_prn(int, int**);

int main() {
	int class;
	printf("Enter Number of class : ");
	scanf("%d", &class);
	int** arr;
	int input = 0;
	int size = 1;
	int cnt = 1;


	arr = (int**)malloc(sizeof(int*) * class);


	if (arr == NULL) {
		printf("malloc failed\n");
		exit(1);
	}
	for (int i = 0; i<class; i++) {
		arr[i] = (int*)malloc(sizeof(int) * size);
		printf("*** Inputing %d class scores ***\n", i + 1);
		while (input >= 0) {
			if (size < cnt) {
				size = cnt;
				arr[i] = (int*)realloc(arr[i] ,sizeof(int) * size);
			}
			if (arr[i] == NULL) {
				printf("malloc failed\n");
				exit(1);
			}
			printf("Enter the score %d : ", cnt);
			scanf(" %4d", &input);
			arr[i][cnt - 1] = input;
			cnt++;
		}
		cnt = 1;
		input = 0;
		printf("\n");
	}
	data_prn(class, arr);
	for (int i = 0; i<class; i++) {
		free(arr[i]);
	}
	free(arr);
	return 0;

}

void data_prn(int class, int** arr) {
	int j;
	for (int i = 0; i < class; i++) {
		j = 0;
		printf("*** %d class scores *** \n", i + 1);
		while (arr[i][j] > 0) {
			printf(" %3d ", arr[i][j]);
			j++;
		}
		printf("\n");
	}
}