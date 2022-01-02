#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999
typedef struct {
char data[100]; // 숫자가 길수도 있기 때문에 문자열로 받음
struct Node *next;
} Node;

typedef struct {
Node *top;
} Stack;


void push(Stack *stack, char *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data); // 문자열이기때문에 문자열을 담는다
    node->next = stack->top; // 현재 스택의 탑을 추가할 노드의 다음이 되도록하고
    stack->top = node;  // 추가할 노드를 스택의 탑이 되도록한다. 
}
char* getTop(Stack *stack) {
    Node *top = stack->top; // 탑을 반환
    return top->data;
}
char* pop(Stack *stack) {
    if (stack->top == NULL) {
    printf("스택 언더플로우가 발생했습니다.\n");
    return -INF;
    }
    Node *node = stack->top;
    char *data = (char*)malloc(sizeof(char) * 100);
    strcpy(data, node->data); // 뺄 노드 데이터 복사  
    stack->top = node->next; //스택의 탑이 뺄 노드의 다음
    free(node); // 노드 삭제 
    return data; // 데이터 반환
}

int getPriority(char *i) { //우선순위 만들기
    if (!strcmp(i, "(")) return 0; // 우선순위가 가장 낮음
    if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
    if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
    return 3; 
}

//s는 입력된 문자열
char* transition(Stack *stack, char **s, int size) {
char res[1000] = ""; 
for (int i = 0; i < size; i++) {
if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
strcat(res, pop(stack)); strcat(res, " "); //문자가 연산자라면 자신보다 우선순위가 높은 것들을 뽑은 뒤에 넣어준다.
}   
push(stack, s[i]);
}
else if (!strcmp(s[i], "(")) push(stack, s[i]);
else if (!strcmp(s[i], ")")) {  
while (strcmp(getTop(stack), "(")) { //닫는 괄호라면 여는 괄호가 나올 때까지
strcat(res, pop(stack)); strcat(res, " ");
}
pop(stack);}
else strcat(res, s[i]); strcat(res, " ");
}
while (stack->top != NULL) {
strcat(res, pop(stack)); strcat(res, " "); //스택에 남은게 있다면 다 꺼내준다.  
}
return res;
}

void calculate(Stack *stack, char **s, int size) {
    int x, y, z;
    for (int i = 0; i < size; i++) {
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
            x = atoi(pop(stack)); //연산자를 만나면 두 개를 뽑고 이를 계산
            y = atoi(pop(stack));
            if (!strcmp(s[i], "+")) z = y + x; // y가 먼저 들어간 원소임
            if (!strcmp(s[i], "-")) z = y - x;
            if (!strcmp(s[i], "*")) z = y * x;
            if (!strcmp(s[i], "/")) z = y / x;
            char buffer[100];
            sprintf(buffer, "%d", z); // 계산된 숫자 형태를 다시 문자로 바꾼다
            push(stack, buffer);
        }
        else {
            push(stack, s[i]);
        }
    }
    printf("%s ", pop(stack));
}


int main(void) {
Stack stack;
stack.top = NULL;
char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
int size = 1;
for (int i = 0; i < strlen(a); i++) {
if (a[i] == ' ') size++;
}
char *ptr = strtok(a, " ");
char **input = (char**)malloc(sizeof(char*) * size);
for (int i = 0; i < size; i++) {
input[i] = (char*)malloc(sizeof(char) * 100);
}
for (int i = 0; i < size; i++) {
strcpy(input[i], ptr);
ptr = strtok(NULL, " ");
}
char b[1000] = "";
strcpy(b, transition(&stack, input, size));
printf("후위 표기법: %s\n", b);
size = 1;
for (int i = 0; i < strlen(b) - 1; i++) { // 마지막은 항상 공백이 들어가므로 1을 빼기
    if (b[i] == ' ') size++;
}
char *ptr2 = strtok(b, " ");
for (int i = 0; i < size; i++) {
strcpy(input[i], ptr2);
ptr2 = strtok(NULL, " ");
}
calculate(&stack, input, size);
system("pause");
    return 0;
}


