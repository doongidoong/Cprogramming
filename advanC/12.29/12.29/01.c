#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_ROWs 5
#define MAX_COLs 4
double average(int[][MAX_COLs]);
int main()
{
	double avg;
	int table[][MAX_COLs] =
	{
	{0, 1, 2, 3},
	{10, 11, 12, 13},
	{20, 21, 22, 23},
	{30, 31, 32, 33},
	{40, 41, 42, 43}
	};
	avg = average(table);
	printf(" average : %.2lf\n", avg);
	return 0;
}
double average(int x[][4])
{
	double sum = 0;
	for (int i = 0; i < MAX_ROWs; i++)
		for (int j = 0; j < MAX_COLs; j++)
			sum += x[i][j];
	return (sum / (MAX_ROWs * MAX_COLs));
}