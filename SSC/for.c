#include <stdio.h>
void star(int N);
void reverse_star(int N);
int main(){
    int N;
    printf("삼각형의 줄을 입력하세요 \n");
    scanf("%d",&N);
    reverse_star(N);    
    return 0;
}

void star(int N){
    int blank = N-1;
    int star = 1;
    for(int i=0;i<N;i++){
        for(int k=0;k<blank;k++){
            printf(" ");}
        for(int s=0;s<star;s++){
            printf("*");}
        blank--;
        star +=2;
        printf("\n");
        }

}

void reverse_star(int N){
    int blank = 0;
    int star = (N*2)-1;
    for(int i=0;i<N;i++){
        for(int k=0;k<blank;k++){
            printf(" ");}
        for(int s=0;s<star;s++){
            printf("*");}
        blank++;
        star -=2;
        printf("\n");
        }

}