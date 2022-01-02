#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999
typedef struct {
char data[100]; // ���ڰ� ����� �ֱ� ������ ���ڿ��� ����
struct Node *next;
} Node;

typedef struct {
Node *top;
} Stack;


void push(Stack *stack, char *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data); // ���ڿ��̱⶧���� ���ڿ��� ��´�
    node->next = stack->top; // ���� ������ ž�� �߰��� ����� ������ �ǵ����ϰ�
    stack->top = node;  // �߰��� ��带 ������ ž�� �ǵ����Ѵ�. 
}
char* getTop(Stack *stack) {
    Node *top = stack->top; // ž�� ��ȯ
    return top->data;
}
char* pop(Stack *stack) {
    if (stack->top == NULL) {
    printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
    return -INF;
    }
    Node *node = stack->top;
    char *data = (char*)malloc(sizeof(char) * 100);
    strcpy(data, node->data); // �� ��� ������ ����  
    stack->top = node->next; //������ ž�� �� ����� ����
    free(node); // ��� ���� 
    return data; // ������ ��ȯ
}

int getPriority(char *i) { //�켱���� �����
    if (!strcmp(i, "(")) return 0; // �켱������ ���� ����
    if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
    if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
    return 3; 
}

//s�� �Էµ� ���ڿ�
char* transition(Stack *stack, char **s, int size) {
char res[1000] = ""; 
for (int i = 0; i < size; i++) {
if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {
strcat(res, pop(stack)); strcat(res, " "); //���ڰ� �����ڶ�� �ڽź��� �켱������ ���� �͵��� ���� �ڿ� �־��ش�.
}   
push(stack, s[i]);
}
else if (!strcmp(s[i], "(")) push(stack, s[i]);
else if (!strcmp(s[i], ")")) {  
while (strcmp(getTop(stack), "(")) { //�ݴ� ��ȣ��� ���� ��ȣ�� ���� ������
strcat(res, pop(stack)); strcat(res, " ");
}
pop(stack);}
else strcat(res, s[i]); strcat(res, " ");
}
while (stack->top != NULL) {
strcat(res, pop(stack)); strcat(res, " "); //���ÿ� ������ �ִٸ� �� �����ش�.  
}
return res;
}

void calculate(Stack *stack, char **s, int size) {
    int x, y, z;
    for (int i = 0; i < size; i++) {
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
            x = atoi(pop(stack)); //�����ڸ� ������ �� ���� �̰� �̸� ���
            y = atoi(pop(stack));
            if (!strcmp(s[i], "+")) z = y + x; // y�� ���� �� ������
            if (!strcmp(s[i], "-")) z = y - x;
            if (!strcmp(s[i], "*")) z = y * x;
            if (!strcmp(s[i], "/")) z = y / x;
            char buffer[100];
            sprintf(buffer, "%d", z); // ���� ���� ���¸� �ٽ� ���ڷ� �ٲ۴�
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
printf("���� ǥ���: %s\n", b);
size = 1;
for (int i = 0; i < strlen(b) - 1; i++) { // �������� �׻� ������ ���Ƿ� 1�� ����
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


