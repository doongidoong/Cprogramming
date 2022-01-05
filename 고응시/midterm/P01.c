#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 
행렬의 사이즈와 영문자를 입력받아 대각선은 \으로, upper diagonal은 대문자로 lower diagonal은
소문자로, 정방행렬에 속하지 않는 부분은 *로 채우는 프로그램을 작성하시오. 행렬의 사이즈는 행
과 열사이에 x를 넣어 입력받으며, 입력받는 영문자는 대문자일수도 소문자일수도 있다.
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