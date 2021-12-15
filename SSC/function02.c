#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int add_element(int (*arr)[2]);

int input_score(char (*name)[30], double (*score), int (*student)) {
	int a1, a2, a3;
	printf("이름을 입력해주세요 ");
	scanf("%s", name[*student]);
	printf("국어 성적을 입력해주세요 ");
	scanf("%d", &a1);
	printf("수학 성적을 입력해주세요 ");
	scanf("%d", &a2);
	printf("영어 성적을 입력해주세요 ");
	scanf("%d", &a3);
	double aver_score = (a1 + a2 + a3) / 3;
	score[*student] = aver_score;
	return 0;
}



int main() {
	double score[5];
	int student = 0;
	char name[5][30];
	for (int i =student; i < 5; i++) {
		input_score(name, score, &i);
		printf("%s ", name[i]);
		printf("%f \n", score[i]);
	}

	return 0;

}

int add_element(int(*arr)[2]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			arr[i][j] += 1;
		}
	}
	return 0;

}