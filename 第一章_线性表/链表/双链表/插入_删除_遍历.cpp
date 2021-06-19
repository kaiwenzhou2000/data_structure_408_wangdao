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
    L->prior = nullptr;
    L->next = nullptr;
    return true;
}

// 在p节点之后插入s节点
/*
 * p    在p后面插入元素
 * s    被插入的元素
 * */
bool InsertNextDNode(DNode *p, DNode *s){
    // p或s是非法值
    if (p == nullptr || s == nullptr){
        return false;
    }

    s->next = p->next;
    // p不是尾结点的情况
    if (p->next != nullptr){
        p->next->prior = s;             // 将p后面元素的前面的指针指向s
    }
    s->prior = p;
    p->next = s;
    return true;
}

// 遍历
void show_double_link_list(DLinkList L){
    DNode *p = L;
    while (p->next != nullptr){
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}

// 删除p的后继节点
bool DeleteNextDNode(DNode *p){
    if (p == nullptr){
        return false;
    }
    DNode *q = p->next;             // q是p的后继节点
    if (q == nullptr){              // p没有后继节点
        return false;
    }
    p->next = q->next;
    if (q->next != nullptr){        // q节点不是最后一个节点
        q->next->prior = p;
    }
    free(q);
    return true;
}

int main(){
    DLinkList L;
    InitDLinkList(L);
    DNode* s = (DNode*) malloc(sizeof(DNode));
    s->data = 1;
    // 插入第一个数据
    InsertNextDNode(L, s);
    show_double_link_list(L);

    // 删除头结点的后继节点
    DeleteNextDNode(L);
    show_double_link_list(L);
    return 0;
}