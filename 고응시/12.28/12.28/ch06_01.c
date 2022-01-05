#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < i+1; j++) {
			printf("%d*%d=%2d ",i,j,i*j);
		}
		printf("\n");	
	}
	return 0;
}
