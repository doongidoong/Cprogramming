/* �Ҵ��� (2 ���� �迭 ó�� ����) �迭 �����ϱ� 
2���� �迭�� ���� ũ�⸦ �������־����.
��ġ�� �츮�� ���� 2���� �迭�� �����͵��� �迭�̹Ƿ� ũ�⸦ ���������� �ʾƵ� ��. 1�����̹Ƿ� 
���� �츮�� ���� �迭�� arr �� ���ҵ��� ����Ű�� �޸� ������ ���޾� �����Ѵٰ� ������ �� ����.
������ arr[3][4] �� *(*(arr + 3)+4) �� �ؼ��Ǿ� 2�����迭ó�� ������ ������.

���⼭ �߿��� ���� 2���� �迭�� �ƴϹǷ� arr�� �����ϸ� arr���� ������ �迭���� �������� ����
���� arr[i]�� �޸� ������ �ʿ���.
*/

#include <stdio.h>
#include <stdlib.h>

void get_average(int **arr, int numStudent, int numSubject);
void get_rank(int **arr, int numStudent, int numSubject);
int main(int argc, char **argv) {
  int i, j, input, sum = 0;
  int subject, students;
  int **arr;   // �츮�� arr[subject][students] �迭�� ���� ���̴�.

  printf("���� �� : ");
  scanf("%d", &subject);

  printf("�л��� �� : ");
  scanf("%d", &students);

  arr = (int **)malloc(sizeof(int *) * subject);
  

  for (i = 0; i < subject; i++) {
    arr[i] = (int *)malloc(sizeof(int) * students);
  }
  
  for (i = 0; i < subject; i++) {
    printf("���� %d ���� --------- \n", i);

    for (j = 0; j < students; j++) {
      printf("�л� %d ���� �Է� : ", j);
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
    printf("���� %d ��� ���� : %d \n", i, sum / numStudent);
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
        printf("�л� %d ����� %d�Դϴ�.\n",i,rank[i]);
        }
    free(rank);
    free(average);
    

}
