#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num=0;
	int count = 0;
	printf("Enter positive int num : ");
	scanf("%d",&num);
	for (int i = 1; i <= num; i++) {
		if((num%i)==0){
			printf("%3d",i);
			count++;
		}
	}
	printf("\n** There are %d divisors of %d **",count, num);
	return 0;
}
