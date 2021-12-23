/*
void 리턴값이 없는 함수.

void a; 는 오류가 남
그러나 void* a;는 가능, 단지 주소값을 담는 변수로 처리
그렇지만 

  void *a;
  double b = 123.3;

  a = &b;

  printf("%lf", *a); 는 오류가 나옴. *a의 타입을 모르기 때문에 따라서

printf("%lf", *(double *)a);로 형변환을 해주어야 함.


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
  