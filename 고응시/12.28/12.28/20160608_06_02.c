#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sumBetween(int, int);
int main() {
	int num = 1;
	int n_sum = 0;
	int count = 0;
	while(1){
		printf("Enter int num between 1 and 100 : ");
		scanf("%d", &num);
		if (num <= 0) break;
		if ((num > 100) || (num%2 == 0)) continue;
		count += 1;
		n_sum += num;
	} 
	
	printf("************************************\n");
	printf("The number of odd data between 1 and 100 : %d \n",count);
	if ((n_sum <= 0)) {
		printf("Sum : 0 and Average : 0.00 ");
		return 0;
	}
	printf("Sum : %d and Average : %.2f ", n_sum, (double)n_sum /count );

	return 0;

}