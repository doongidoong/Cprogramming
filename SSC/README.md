# Cprogramming
씹어먹는 C언어<br>
구조체부터 깃허브에 기록한다.

<정리>

- 조건문
1. IF문 내부의 조건을 검사해 프로그램의 진행 경로를 결정<br>
2. IF문은 조건의 개수가 많지 않을 때 사용하는 것이 유리<br>
if (조건 1) {
// 조건 1에 부합할 때
}
else if (조건2) {
// 조건 1에 부합하지 않지만 조건 2에 부합할 때
}
else {
// 위 조건들에 모두 부합하지 않을 때
}
<p>

3. Switch문은 다양한 조건이 존재할 때 사용하면 소스코드를 짧게 유지할 수 있음<br>

switch (확인 대상) {
case 값1:
// 값 1에 부합할 때
case 값2:
// 값 2에 부합할 때
Default:
// 모든 경우
}
<p>
확인 대상에는 char, int, double, long 등의 자료형을 사용할 수 있음. ex switch(num){case 1: ~ case 2:~}

<p>

- 구조체
1. 구조체란 여러 개의 변수를 묶어 하나의 객체로 표현하고자 할때 사용 <br>
2. 기본적으로 구조체의 변수에 접근할 때는 온점(.)을 사용<br>
3. 하나의 구조체 변수만 사용하는 경우 정의와 동시에 선언을 할 수도 있음.
 이 경우 변수는 전역 변수로 사용.<br>

struct test {
int a;
} t;
<p>
 
4. typedef 키워드를 이용하면 임의의 자료형을 만들 수 있으므로 선언이 더 짧아짐.<br>
5. 구조체의 변수를 한 번에 초기화하기 위해서는 중괄호에 차례대로 변수의 값을 넣음.<br>

typedef struct { // 학생 구조체 정의
int a;
int b;
} test;

int main(void) {
test t = { 99, 100 };
return 0;
}
<p>

6. 구조체가 포인터 변수로 사용되는 경우 내부 변수에 접근할 때 화살표(->)를 사용.<br>
->가 *보다 우선 순위가 높음

7. 구조체 안에 또다른 구조체를 선언할 수 있음<br>

struct employee {
  int age;
  int salary;
};<br>
struct company {
  struct employee data;
  char name[10];
};<p>

- 공용체

1. 공용체는 메모리를 공유하는 것, 메모리 시작 주소가 동일함 <br>

union A {

  int i;

  char j;
};

int main() {

  union A a; 

  a.i = 0x12345678; 
  
  printf("%x", a.j); 
  
  return 0; 
}
<p>
실행결과: 78 (0x12가 아님)

2. 컴퓨터에서 메모리에 수를 저장할 때의 방법이 두가지 있음, 빅에디안 리틀에디안, 주로 리틀 에디안이 사용됨. 뒤에 두개부터 저장됨<br>
0X12345678의 경우 순서가 0X78563412라고 보면 됨.하지만 지정된 형식의 byte가 커짐에 따라 78563412가 아닌 5678, 345678, 1235678으로 출력됨.
<br>
빅 에디안: 낮은 주소값에 상위 비트를 적는 방식<br>
리틀 에디안 : 높은 주소값에 상위 비트를 적는 방식<br>


- 열거형

1. 열거형을 사용할 시 enum { RED, BLUE, WHITE, BLACK };가 0,1,2,3이라는 정수값을 매겨주게 됨.

2. 첫 수를 enum { RED = 3, BLUE, WHITE, BLACK };라는 방식으로 지정해줄 수도 있음.



