#include <stdio.h>
#include <stdlib.h>

// 1. 单链表 (Singly Linked List)
typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

SNode* createSNode(int data) {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 2. 双向链表 (Doubly Linked List)
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

DNode* createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 3. 循环链表 (Circular Linked List)
// 结构与单链表相同，区别在于最后一个节点指向第一个节点
typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

int main() {
    printf("--- 不同类型链表示例 ---\n");

    // 单向链表演示
    SNode* headS = createSNode(1);
    headS->next = createSNode(2);
    printf("单向链表: %d -> %d\n", headS->data, headS->next->data);

    // 双向链表演示
    DNode* headD = createDNode(10);
    DNode* secondD = createDNode(20);
    headD->next = secondD;
    secondD->prev = headD;
    printf("双向链表: %d <-> %d\n", headD->data, headD->next->data);

    // 循环链表演示
    CNode* headC = (CNode*)malloc(sizeof(CNode));
    headC->data = 100;
    CNode* secondC = (CNode*)malloc(sizeof(CNode));
    secondC->data = 200;
    headC->next = secondC;
    secondC->next = headC; // 尾端指向头端
    printf("循环链表: %d -> %d -> (回到开头 %d)\n", headC->data, secondC->data, secondC->next->data);

    // 这里的 free 略过，实际使用中注意释放内存
    return 0;
}
