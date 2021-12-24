/* 할당한 (2 차원 배열 처럼 생긴) 배열 전달하기 
2차원 배열은 원래 크기를 지정해주어야함.
그치만 우리가 만든 2차원 배열은 포인터들의 배열이므로 크기를 지정해주지 않아도 됨. 1차원이므로 
또한 우리가 만든 배열은 arr 의 원소들이 가리키는 메모리 공간이 연달아 존재한다고 보장할 수 없음.
하지만 arr[3][4] 는 *(*(arr + 3)+4) 로 해석되어 2차원배열처럼 접근이 가능함.

여기서 중요한 점은 2차원 배열이 아니므로 arr을 해제하면 arr안의 포인터 배열들은 해제되지 않음
따라서 arr[i]의 메모리 해제도 필요함.
*/

#include <stdio.h>
#include <stdlib.h>

void get_average(int **arr, int numStudent, int numSubject);
void get_rank(int **arr, int numStudent, int numSubject);
int main(int argc, char **argv) {
  int i, j, input, sum = 0;
  int subject, students;
  int **arr;   // 우리는 arr[subject][students] 배열을 만들 것이다.

  printf("과목 수 : ");
  scanf("%d", &subject);

  printf("학생의 수 : ");
  scanf("%d", &students);

  arr = (int **)malloc(sizeof(int *) * subject);
  

  for (i = 0; i < subject; i++) {
    arr[i] = (int *)malloc(sizeof(int) * students);
  }
  
  for (i = 0; i < subject; i++) {
    printf("과목 %d 점수 --------- \n", i);

    for (j = 0; j < students; j++) {
      printf("학생 %d 점수 입력 : ", j);
      scanf("%d", &input);

      arr[i][j] = input;
    }
  }

  //get_average(arr, students, subject);
  get_rank(arr,students,subject);
  for (i = 0; i < subject; i++) {
    free(arr[i]);
  }
  free(arr);
  return 0;
}
void get_average(int **arr, int numStudent, int numSubject) {
  int i, j, sum;

  for (i = 0; i < numSubject; i++) {
    sum = 0;
    for (j = 0; j < numStudent; j++) {
      sum += arr[i][j];
    }
    printf("과목 %d 평균 점수 : %d \n", i, sum / numStudent);
  }
}

void get_rank(int **arr, int numStudent, int numSubject ){
    int *rank = (int*)malloc(sizeof(int)*numStudent);
    int *average = (int*)malloc(sizeof(int)*numStudent);
    
  
    for(int j=0; j< numStudent;j++){
        int sum=0;
        for(int i=0;i<numSubject;i++){
            sum += arr[i][j];
            
        }
        average[j] =sum;
    }
    
    for(int j=0;j<numStudent;j++){
        int k=0;
        int temp=0;
        for(int i=0;i<numStudent;i++){
        if(average[i]>k){
            k=average[i];
            temp=i;
        }
        }
        rank[temp] = j+1;
        average[temp] = -1;}

    for(int i=0;i<numStudent;i++){
        printf("학생 %d 등수는 %d입니다.\n",i,rank[i]);
        }
    free(rank);
    free(average);
    

}
