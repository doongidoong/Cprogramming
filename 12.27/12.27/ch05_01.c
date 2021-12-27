#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char lowerToIpper(char);
int main(void) {
	char a;
	printf("Enter one character to change to uppercase letter : ");
	scanf("%c", &a);
	a = lowerToIpper(a);
	printf("Result : %c \n", a);
	system("pause");
	return 0;
}

char lowerToIpper(char a){
	if ((a >= 97) && (a<=122)){
		return a - 32;
	}
	else return a;
}