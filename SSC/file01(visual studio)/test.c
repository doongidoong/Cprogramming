/* "str.h"�� ���� ���� ����. ������Ͽ� char compare(char *str1, char *str2);�� ���� ��
�� ���ϰ� str.c ���� ��� "str.h"�� include�ϸ� ��.
��ó����� ������ ������ �����.
#include "str.h" ��� ����� str.h �� �־��� ����, �� char compare(char *str1, char *str2); �� �������� �����ϱ� ���� �ٲ�� ����.
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
		printf("%s �� %s �� ���� ���� �Դϴ�. \n", str1, str2);
	}
	else {
		printf("%s �� %s �� �ٸ� ���� �Դϴ�. \n", str1, str2);
	}
	return 0;
}