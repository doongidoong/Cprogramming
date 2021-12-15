#include <stdio.h>
#include<math.h>
/* 큰 수를 다루는 구조체
1. BigNum 구조체의 변수들의 덧셈, 뺄셈을 수행하는 함수를 작성.
2. BigNum 구조체 변수들의 곱셈을 수행하는 함수
3. BigNum 구조체 변수들의 나눗셈을 수행하는 함수
*/
struct BigNum {
  int i_digit[100];   // 정수 부분
  int d_digit[100];   // 소수 부분
  int i_total_digit;  // 전체 사용되고 있는 정수부분 자리수
  int d_total_digit;  // 전체 사용되고 있는 소수부분 자리수
  char sign;  // 부호, 0 이면 양수, 1 이면 음수. 0 은 양수로 간주한다.
};

int set_num(struct BigNum *Num, char *realnum){
    int i=0;
     while(*realnum){
        Num ->i_digit[i] =(*realnum)-48;
        i++;
        realnum++;
        if(*realnum=='.'){
            realnum++;
            break;
        }
    }
    (*Num).i_total_digit=i;
    int d=0;
     while(*realnum){
        Num ->d_digit[d] =(*realnum)-48;
        d++;
        realnum++;
    }
    (*Num).d_total_digit=d;
    
    return 0;
}

int add(struct BigNum *Num1,struct BigNum *Num2){
    int i_sum[101];
    int d_sum[100];
/*    
    if((*Num2).i_total_digit>(*Num2).i_total_digit){
        n1 = Num1;
        n2 = Num2;
    }
    else {
        n2 = Num1;
        n1 = Num2;
    }
*/

}

int main(){
    struct BigNum num1;
    set_num(&num1,"1231413415.23123");
    add(&num1,&num1);
   return 0;



}