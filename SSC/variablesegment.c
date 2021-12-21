
#include <stdio.h>

int global = 0; //���� ����

int function() {
  global++;
  return 0;
}

int* function2() {
  static int a = 2; //���� ����
  return &a;
}
/*
static int a = 2 ��� ������ �� �� �� ���� �Ǹ�, 
�� ���� ���� function �� �������� �ʴ��� a ��� ���� ������ �̹� ���ǵǾ� �ִ� ����
*/

int main() {
  global = 10;
  function();
  printf("%d \n", global);  

  int* pa = function2(); 
  printf("%d \n", *pa);
  return 0;
}

/*
 ���� ����  ���� ���� ���� ������ �������� �ʴ� ���� ����
 ���� ������ ���� �����ʹ� �޸� �޸��� ������ ����(Data segment)�� �Ҵ� 

 �Ϲ������� ���ǵ� �������� �ڽ��� ���ǵ� ������ �������� �� �ı���. �� ���� ���� ���̳ĸ�, 
 �ڽ��� ���ǵ� ��ġ�� �����ϰ� �ִ� {} �� ��� �� �ش� ������ ������� �ȴٴ� ��

 ������ ������ ����� �ı����� �ʴ� ������ ����. �̸� ����������� ��.
 ���� ������ ��� ���� ���� ó�� ������ ������ ����ǰ� ���α׷��� ����� �� �ı�

���α׷��� RAM �� ����,��� ������ RAM ���� �ö���� �ȴٴ� �� 
���⼭ '���α׷��� ��� ����' �̶� �ϸ� ���α׷��� �ڵ�� ���α׷��� �����͸� ��� �ǹ�
RAM ���� �ö���� ���α׷��� ������ ũ�� ����� �ڵ� ���׸�Ʈ(Code Segment) �� 
������ ���׸�Ʈ(Data Segment) �� �з�

------------------------   �Ʒ��� ������ �޸� �ּ� ������
���� : �������� ��ġ
------------------------
�� 
------------------------
������ ����: ���� ����, ���� ����
------------------------
read only data: ����� ���ͷ�
------------------------
code ����
------------------------
*/