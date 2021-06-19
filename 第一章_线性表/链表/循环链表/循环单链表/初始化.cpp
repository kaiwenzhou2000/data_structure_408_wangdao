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
    L->next = L;                  // 指向自己，表示这是一个空链表
    return true;
}

// 判断循环链表是否为空
bool Empty(LinkList L){
    if (L->next == L){
        return true;
    }
    return false;
}

int main(){
    LinkList L;
    InitList_with_head(L);
    printf("这个循环双链表是%s", Empty(L) == true?"空":"非空");
    return 0;
}