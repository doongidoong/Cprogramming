#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int arr[3][4];
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = i + 3*j+1;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}