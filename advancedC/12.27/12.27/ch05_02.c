#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char a;
	int num1, num2;
	printf("������ �ǿ�����1 �ǿ�����2 ������� �Է�: ");
	scanf("%c %d %d", &a , &num1, &num2);
	if (a == 43) {
		printf("%d + %d = %d \n",num1,num2,num1+num2);
	}
	else if (a == 42) {
		printf("%d * %d = %d \n", num1, num2, num1 * num2);
	}
	else {
		printf("������� �ʴ� ������ \n");
	}
	system("pause");
	return 0;
}

