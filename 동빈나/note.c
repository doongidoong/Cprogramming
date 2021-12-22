#include <stdio.h>
#define INF 10000


typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head;

void addFront(Node *root, int data){ //  ��尡 ����Ű�� ���� ���� ����� ����Ű�� ��尡 ���� ���� ����Ŵ
    Node *node =(Node*)malloc(sizeof(Node));
    node ->data = data;
    node ->next = root ->next;
    root ->next = node;
}

void removeFront(Node *root){ // ��-> ��-> ��->
    Node *node = root->next;
    root->next = node->next;
    free(node);
}
void freeAll(Node *root) { // ���� ����Ʈ �޸� ���� �Լ�
    Node *cur = root->next;
    while(cur){
        Node *next = cur->next;
        free(cur);
        cur = next; 
    }
}
void showAll(Node *root) { //���� ����Ʈ ��ü ��� �Լ�
    Node *cur = root->next;
    while(cur!=NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
}


int main(void) {
    head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 7);
    addFront(head, 9);
    addFront(head, 8);
    removeFront(head);
    showAll(head);
    freeAll(head);
    system("pause");
    return 0;
}
