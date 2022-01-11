#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int token(char** c, char s[]);
int printa(char** c, int s);
int sort(char** c, int s);
// this is sorting test program
int main() {
	char s[101];
	printf("Enter one sentence (maximum length 100) : ");
	gets_s(s, 101);
	char** c = (char**)malloc(sizeof(char*) * 100);

	int i = token(c, s);
	sort(c, i);
	printa(c, i);

	
	free(c);
	return 0;
}

int token(char **c, char s[]) {
	char* temp = (char*)malloc(sizeof(char) * 100);
	temp = strtok(s, " \n");
	int i = 0;
	while (temp != NULL) {
		c[i] = (char*)malloc(sizeof(char) * strlen(temp));
		strcpy(c[i], temp);
		temp = strtok(NULL, " \n");
		i++;

	}

	free(temp);
	return i;
}
int printa(char** c, int s) {
	printf("************* sorted token list *************\n");
	for (int i = 0; i < s; i++) {
		printf("%s \n", c[i]);
	
	}


}
int sort(char** c, int s) {
	char* temp;
	for (int i = 0; i < s; i++) {
		for (int j = i+1; j < s; j++) {
			if (c[i][0] > c[j][0]) {
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
}