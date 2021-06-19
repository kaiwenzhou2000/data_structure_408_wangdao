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

bool Empty(DLinkList L){
    if (L->next == nullptr){
        return true;
    }
    return false;
}

int main(){
    DLinkList L;
    InitDLinkList(L);
    printf("该双向链表是%s", Empty(L) == true ? "空" : "非空");
    return 0;
}