#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
void str_prn(int, char**);
int compare_count(char* str1, char* str2);
int main()
{
	char tmp[51];
	char** str;
	int i;
	str = (char**)malloc(5 * sizeof(char*));
	i = 0;
	while (1)
	{
		printf("Enter %dth string : ", i + 1);
		gets_s(tmp, sizeof(tmp));
		str[i] = (char*)malloc(strlen(tmp) + 1);
		strcpy(str[i], tmp);
		i++;
		if (i == 5)
			break;
	}
	str_prn(5, str);
	i = 0;
	char s[21];
	char* p = s;
	printf("Enter the word you want to find : ");
	scanf("%s", s);
	for (int i = 0; i < 5; i++) {
		printf("%d sentence : %d times found\n", i + 1, compare_count(str[i], s));
	}

	while (i < 5)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return 0;
}
void str_prn(int n, char** str)
{
	int i;
	printf("*********************************\n");
	for (i = 0; i < n; i++)
	{
		printf("%d : %s\n", i + 1, *(str + i));
	}
	printf("*********************************\n");
}
int compare_count(char* str1, char* str2) {
	const char delimiters[] = " \t\n";
	char* tok;
	tok = strtok(str1, delimiters);
	int cnt = 0;
	while (tok != NULL)
	{
		if (strcmp(tok, str2) == 0)
			cnt++;
		tok = strtok(NULL, delimiters);
	}
	return cnt;

}
