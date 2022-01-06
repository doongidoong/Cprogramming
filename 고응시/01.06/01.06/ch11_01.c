#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void){

	FILE* fp1 = fopen("ch11_in.txt", "w");
	if (fp1 == NULL) {
		printf("error\n");
		return 1;
	}
	for (int i = 1; i < 6; i++) {
		fprintf(fp1,"%3d ", i * 10 + 1);
		fprintf(fp1, "%3d\n", i * 10 + 2);
	}
	int state = fclose(fp1);
	if (state != 0){
		printf("error\n");
		return 1;
	}
	FILE* fp1_r, *fp2;
	fp1_r = fopen("ch11_in.txt", "r");
	fp2 = fopen("ch11_out.txt", "w");
	if ((fp1_r == NULL) || (fp2 == NULL)) {
		printf("error\n");
		return 1;
	}
	int data[2];
	while (1) {
		fscanf(fp1_r, "%d %d", &data[0], &data[1]);
		if (feof(fp1_r))
			break;
		fprintf(fp2, "%3d \n", data[0]+data[1]);
	}
	fclose(fp1_r);
	fclose(fp2);
	return 0;
}


