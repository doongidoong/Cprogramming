#include <stdio.h>
#include<math.h>
/* ū ���� �ٷ�� ����ü
1. BigNum ����ü�� �������� ����, ������ �����ϴ� �Լ��� �ۼ�.
2. BigNum ����ü �������� ������ �����ϴ� �Լ�
3. BigNum ����ü �������� �������� �����ϴ� �Լ�
*/
struct BigNum {
  int i_digit[100];   // ���� �κ�
  int d_digit[100];   // �Ҽ� �κ�
  int i_total_digit;  // ��ü ���ǰ� �ִ� �����κ� �ڸ���
  int d_total_digit;  // ��ü ���ǰ� �ִ� �Ҽ��κ� �ڸ���
  char sign;  // ��ȣ, 0 �̸� ���, 1 �̸� ����. 0 �� ����� �����Ѵ�.
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