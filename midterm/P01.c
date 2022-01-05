#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 
����� ������� �����ڸ� �Է¹޾� �밢���� \����, upper diagonal�� �빮�ڷ� lower diagonal��
�ҹ��ڷ�, ������Ŀ� ������ �ʴ� �κ��� *�� ä��� ���α׷��� �ۼ��Ͻÿ�. ����� ������� ��
�� �����̿� x�� �־� �Է¹�����, �Է¹޴� �����ڴ� �빮���ϼ��� �ҹ����ϼ��� �ִ�.
*/

int smallnum(int a, int b) {
	if (a > b) return b;
	else return a;
}

void printdiag(int i, int j, int square, char a) {
	if (i >= square || j >= square) printf("* ");
	else{
		if (i == j) printf("\\ ");
		if (i > j) printf("%c ",a);
		if (i < j) printf("%c ",a-32);
	}

}

int main() {
	char c;
	char str[10];
	scanf("%s %d", str, &c);
	int a, b;
	a = str[0] - 48;
	b = str[2] - 48;
	if (c < 95) c += 32;
	int square = smallnum(a, b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printdiag(i, j, square, 'a');
		}
		printf("\n");
	}

	return 0;
}