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
    int a = (*Num1).d_total_digit;
    int b = (*Num2).d_total_digit;
    int check=0;
    int num =0;
    int d=0;
    int i=0;
    while(1){
        if((a==0)&& (b==0)){
            break;
        }
        d++;
        num=check;
        check=0;
        if(a>b){
            num += (*Num1).d_digit[a-1];
            if(num>=10){
                check=1;
                num -= 10;
            }
            d_sum[a-1] = num;
            a--;}
        if(a<b){
            num += (*Num2).d_digit[b-1];
            if(num>=10){
                check=1;
                num -= 10;
            }
            d_sum[b-1] = num;
            b--;}
        if(a==b){
            num += (*Num1).d_digit[a-1]+(*Num2).d_digit[b-1];
            if(num>=10){
                check=1;
                num -= 10;
            }
            d_sum[a-1] = num;
            a--;
            b--;
        }
    }
    a = (*Num1).i_total_digit;
    b = (*Num2).i_total_digit;
    while(1){
        if((a==0)||(b==0)){
            break;
        }
        i++;
        num= check;
        num += (*Num1).i_digit[a-1]+(*Num2).i_digit[b-1];
        check=0;
        if(num>=10){
            check=1;
            num -= 10;
        }
        if(a>b){
            i_sum[a-1] = num;
        }
        if(b>=a){
            i_sum[b-1] = num;
        }
        a--;
        b--;
    }
    while(a){
        num= check;
        num += (*Num1).i_digit[a-1];
        check=0;
        if(num>=10){
            check=1;
            num -= 10;
        }
        i_sum[a-1] = num;
        a--;
        i++;
    }
    while(b){
        num= check;
        num += (*Num2).i_digit[b-1];
        check=0;
        if(num>=10){
            check=1;
            num -= 10;
        }
        i_sum[b-1] = num;
        b--;
        i++;
    }
    if(check==1){
        i_sum[0]+=10;
    }
    for(int s=0;s<i;s++){
        printf("%d",i_sum[s]);
    }
    printf(".");
    for(int s=0;s<d;s++){
        printf("%d",d_sum[s]);
    }
    return 0;

};

int main(){
    struct BigNum num1;
    set_num(&num1,"1231413415.23188");
    struct BigNum num2;
    set_num(&num2,"9991413415.23188");
    add(&num1,&num2);
   return 0;
}