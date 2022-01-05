#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main() {

	int n;
	scanf("%d", &n);
	int *arr;
	printf("%d 명의 성적을 입력하세요: ", n);
	arr = (int*)malloc(sizeof(int)*n);
	int i = 0;

	while (i<n)
	{
	scanf("%d", &arr[i++]);
	printf("");
	}

	int sumn=0;
	int maxn=0;

	for (int i = 0; i < n; i++) {
		sumn += arr[i];
		if (arr[i] > maxn) {
			maxn = arr[i];
		}
	}
	printf("%d %d %.1f", sumn, maxn, sumn / (double)n);

	free(arr);
	return 0;
}