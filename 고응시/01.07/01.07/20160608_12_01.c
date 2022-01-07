#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
	double x;
	double y;
} POINTER;

double pointer_dist(POINTER*, POINTER*);

int main() {
	int n;
	printf("Number of input data? : ");
	scanf("%d", &n);
	POINTER** arrp = (POINTER**)malloc(sizeof(POINTER*) * n);
	for (int i = 0; i < n; i++) {
		printf("%d - Enter x,y coordinate values : ",i+1);
		arrp[i] = (POINTER*)malloc(sizeof(POINTER) * 2);
		scanf("%lf %lf", &(arrp[i]->x), &(arrp[i]->y));
	}
	printf("\n*********************************************\n");
	for (int i = 0 ; i < n; i++) {
		printf("The distance between (%.2lf, %.2lf) and (%.2lf, %.2lf) pointers : %.2lf \n", arrp[2 * i]->x, arrp[2 * i]->y, arrp[2 * i+1]->x, arrp[2 * i + 1]->y, pointer_dist(arrp[2 * i], arrp[2 * i + 1]));
	} 
	for (int i = 0; i < n; i++) {
		free(arrp[i]);
	}
	free(arrp);
	return 0;
}

double pointer_dist(POINTER* a, POINTER* b) {
	
	return sqrt(pow((a->x) - (b->x), 2) + pow((a->y) - (b->y), 2));
}

