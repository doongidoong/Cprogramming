/* 인자를 가지는 메인 함수 */
#include <stdio.h>

int main(int argc, char **argv) {
  int i;
  int num1 = *(char*)argv[1];
  int num2 = *(char*)argv[3];
  
  num1 -= 48;
  num2 -= 48;
  switch (*argv[2]) {
        case '+':
            printf("%d", num1 + num2);
            break;
        case '-':
            printf("%d", num1 - num2);
            break;
        case '*':
            printf("%d", num1 * num2);
            break;
        case '/':
            printf("%f", (float)num1 / num2);
            break;
        default:
            printf("기대한 입력이 아닙니다. 다시 시도해주세요. \n");
    }

  return 0;
}