#include <stdio.h>
#include <stdlib.h>

int main() {
  int width, height;
  printf("�迭 �� ũ�� : ");
  scanf("%d", &width);
  printf("�迭 �� ũ�� : ");
  scanf("%d", &height);

  int(*arr)[width] = (int(*)[width]) malloc (height * width * sizeof(int)); //2���� �迭�̹Ƿ� width �� �� ���� ���������
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int data;
      scanf("%d", &data);
      arr[i][j] = data;
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);
}