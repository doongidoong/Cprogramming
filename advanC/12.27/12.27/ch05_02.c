#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char a;
	int num1, num2;
	printf("연산자 피연산자1 피연산자2 순서대로 입력: ");
	scanf("%c %d %d", &a , &num1, &num2);
	if (a == 43) {
		printf("%d + %d = %d \n",num1,num2,num1+num2);
	}
	else if (a == 42) {
		printf("%d * %d = %d \n", num1, num2, num1 * num2);
	}
	else {
		printf("허용하지 않는 연산자 \n");
	}
	system("pause");
	return 0;
}

