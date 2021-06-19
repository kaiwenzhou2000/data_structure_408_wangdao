//
// Created by kaiven on 2021/6/19.
//

#include "stdio.h"
#include "stdlib.h"

typedef struct DNode{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

// 初始化一个双向链表（带表头）
bool InitDLinkList(DLinkList &L){
    L = (DNode*) malloc(sizeof(DNode));
    // 分配失败
    if (L == nullptr){
        return false;
    }

    // 将前面和后面的指针都指向null
    L->prior = L;
    L->next = L;
    return true;
}

// 插入元素
/*
 * p表示在这个元素之后查入元素
 * s表示需要插入的元素
 *
 * 由于是循环链表，这里不需要考虑p是尾结点的特殊情况
 * */
bool InsertNextDNode(DNode *p, DNode *s){
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 删除p后面的元素
bool DeleteNextDNode(DNode *p){
    DNode *q = p->next;             // q是p后面的元素，也是要删除的元素
    q->next->prior = p;
    free(q);
    return true;
}

int main(){
    DLinkList L;
    InitDLinkList(L);
    DNode *s = (DNode*) malloc(sizeof(DNode));
    s->data = 1;
    InsertNextDNode(L, s);
    DeleteNextDNode(L);
    return 0;
}