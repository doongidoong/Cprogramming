/* "str.h"로 만들 수도 있음. 헤더파일에 char compare(char *str1, char *str2);를 넣은 뒤
본 파일과 str.c 파일 모두 "str.h"를 include하면 됨.
전처리기는 컴파일 이전에 실행됨.
#include "str.h" 라는 명령은 str.h 에 있었던 내용, 즉 char compare(char *str1, char *str2); 로 컴파일이 시작하기 전에 바뀌어 버림.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "str.h"

int main() {
	char str1[20];
	char str2[20];

	scanf("%s", str1);
	scanf("%s", str2);

	if (compare(str1, str2)) {
		printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);
	}
	else {
		printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);
	}
	return 0;
}