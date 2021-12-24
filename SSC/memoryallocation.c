/* 동적 할당의 활용 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int student;  // 입력 받고자 하는 학생 수
  int i, input;
  int *score;   // 학생 들의 수학점수 변수
  int sum = 0;  // 총점

  printf("학생의 수는? : ");
  scanf("%d",&student);


  score = (int *)malloc(sizeof(int)*student);
  for(i=0;i<student;i++){
      printf("학생 %d 의 점수 : ", i);
      scanf("%d",&input);
      score[i] = input;

  }

  for (i = 0; i < student; i++) {
    sum += score[i];
  }

  printf("전체 학생 평균 점수 : %d \n", sum / student);
  free(score);
  return 0;
}
/*

동적메모리 할당은 힙 영역에서 이루어짐.
스택 이나, 데이타 영역, Read Only Data 부분은 동적할당으로 못 건드림.
메모리의 힙 부분은 사용자가 자유롭게 할당하거나 해제할 수 있음, 따라서 우리의 malloc 함수도 이 힙을 이용
*/