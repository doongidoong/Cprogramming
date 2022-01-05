#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char c1, c2 ,c3;
	
	printf("Enter three character ");
	scanf("%c%c%c",&c1,&c2,&c3);
	printf("Three character are %c, %c, and %c \n",c1,c2,c3);
	return 0;
}