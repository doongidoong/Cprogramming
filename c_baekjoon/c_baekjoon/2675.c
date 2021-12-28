#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num=0;
	int repeat=0;
	
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		char c[20];
		char* pc = c;
		scanf("%d %s", &repeat, &c);
		while (*pc) {
			for (int j = 0; j < repeat; j++) {
				printf("%c", *pc);
			}
			pc++;
		}
		printf("\n");
	}

	system("pause");
	return 0;
}