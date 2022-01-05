#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	char var, var2, oper;
	int num;
	int num2;
	int check = 0;
	double result;
	printf("******************************************************\n");
	
	printf("Enter variable assignment(ex a = 314) : ");
	scanf("%c %c %d", &var,&oper, &num);
	if(oper!=61){
		printf("\nPlease enter a correct operator");
		return 0;
	}
	rewind(stdin);
	printf("\n******************************************************\n");
	printf("Enter a math expression using variable(ex: a + 10) : ");
	scanf("%c %c %d", &var2, &oper, &num2);
	if ((oper == 47) && (num2==0)) {
		printf("Can't be divided into zero \n");
		check = 1;
	}
	if (var != var2) {
		printf("Only use defined variable! \n");
		check = 1;
	}
	if (check == 1) return 0;
	else {
		switch (oper) {
		case 43:
			printf("\n>>>>>>>>>> Result %c + %d = %d", var,num2 , num + num2);
			break;
		case 45:
			printf("\n>>>>>>>>>> Result %c - %d = %d", var, num2, num - num2);
			break;
		case 42:
			printf("\n>>>>>>>>>> Result %c * %d = %d", var, num2, num * num2);
			break;
		case 47:
			
			result = (double)num / num2;
			printf("\n>>>>>>>>>> Result %c / %d = %.2f", var, num2, result);
			break;
		default:
			printf("\nPlease enter a correct operator");
		}
	}

	return 0;
}