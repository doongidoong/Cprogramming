#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int SumOfDivisors(int);
int IsSame(int,int);

int main() {
	int rand_num;
	int divisors;
	int answer;
	srand((unsigned)time(NULL));
	rand_num = rand()%51;
	divisors = SumOfDivisors(rand_num);
	printf("The random number is %d \n", rand_num);
	printf("**************************************\n");
	printf("Enter the sum of divisors : %d",divisors);
	scanf("%d", &answer);
	if (IsSame(divisors, answer)) printf("The sum of divisors of %d is equal to %d", divisors, answer);
	else printf("Not equal");

	return 0;

}


int SumOfDivisors(int x)
{
	int sum = 0;
	int i;
	for (i = 1; i <= x; i++)
	{
		if ((x % i) == 0)
			sum += i;
	}
	return sum;
}

int IsSame(int a, int b) {
	if (a == b)
		return 1;
	else
		return 0;
}
