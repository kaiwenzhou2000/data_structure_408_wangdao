//
// Created by kaiven on 2021/6/19.
//

#include "stdio.h"
#include "stdlib.h"

// 单个节点的数据结构
typedef struct LNode{
    int data;                       // 每个节点存放的一个数据元素
    struct LNode *next;             // 指针指向下一个节点
}LNode, *LinkList;

// 初始化带头结点的链表
bool InitList_with_head(LinkList &L){
    L = (LNode*) malloc(sizeof(LNode)); // 分配一个头结点
    if (L == nullptr){                  // 内存分配失败
        return false;
    }
    L->next = nullptr;                  // 指向空，表示这是一个空链表
    return true;
}

// 后插操作
/*
 * p 是指向需要在后面插入元素的指针
 * e 是需要插入的元素
 * */
bool InsertNextNode(LNode *p, int e){
    if (p == nullptr){                  // 给定的元素指针为空
        return false;
    }

    LNode *s = (LNode*)malloc(sizeof(LNode));       // 给新增节点分配内存
    if (s == nullptr){              // 分配内存失败
        return false;
    }
    // 将节点s连接到p之后
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


// 前插操作
/*
 * p 是指向需要在后面插入元素的指针
 * e 是需要插入的元素
 * */
bool InsertPriorNode(LNode *p, int e){
    if (p == nullptr){                  // 给定的元素指针为空
        return false;
    }
    LNode *s = (LNode*) malloc(sizeof(LNode));
    if (s == nullptr){
        return false;
    }
    // 由于单向链表难以知道节点的前面一个元素的地址，所以可以将s插在p节点之后，然后交换s和p节点的值
    s->next = p->next;
    p->next = s;
    // 交换元素值
    s->data = p->data;
    p->data = e;
    return true;
}

// 展示带头结点的链表
void show_link_list_with_head(LinkList &L){
    LNode *p = L->next;
    printf("带头结点的链表:");
    while (p != nullptr){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    LinkList L;
    InitList_with_head(L);
    // 后插
    InsertNextNode(L, 1);
    // 展示
    show_link_list_with_head(L);
    // 前插
    InsertPriorNode(L->next, 2);
    // 展示
    show_link_list_with_head(L);
}