/*
void ���ϰ��� ���� �Լ�.

void a; �� ������ ��
�׷��� void* a;�� ����, ���� �ּҰ��� ��� ������ ó��
�׷����� 

  void *a;
  double b = 123.3;

  a = &b;

  printf("%lf", *a); �� ������ ����. *a�� Ÿ���� �𸣱� ������ ����

printf("%lf", *(double *)a);�� ����ȯ�� ���־�� ��.


*/

#include <stdio.h>

void add_one(int *p){
    int *num = p;
    *num +=1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}

int main() {
  int a = 1;
  int b = 3;
  printf("Before : %d \n", a);
  add_one(&a);
  printf("After : %d \n", a);

  printf("Before : %d %d \n", a,b);
  swap(&a,&b);
  printf("After : %d %d  \n", a, b);

  return 0;
}
  