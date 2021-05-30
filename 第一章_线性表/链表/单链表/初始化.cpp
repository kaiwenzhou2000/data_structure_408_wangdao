//
// Created by kaiven on 2021/5/30.
//

#include "stdio.h"
#include "stdlib.h"

// 单个节点的数据结构
typedef struct LNode{
    int data;                       // 每个节点存放的一个数据元素
    struct LNode *next;             // 指针指向下一个节点
}LNode, *LinkList;

// 不带头结点的单链表
bool InitList_without_head(LinkList &L){
    L = nullptr;                    // 空表，暂时还没有任何节点
    return true;
}

// 判断不带头结点的链表是否为空
bool is_empty_without_head(LinkList &L){
    if(L == nullptr){
        return true;
    }
    return false;
}

// 初始化带头结点的链表
bool InitList_with_head(LinkList &L){
    L = (LNode*) malloc(sizeof(LNode)); // 分配一个头结点
    if (L == nullptr){                  // 内存分配失败
        return false;
    }
    L->next = nullptr;                  // 指向空，表示这是一个空链表
    return true;
}

// 判断带头节点的链表是否为空
bool is_empty_with_head(LinkList &L){
    if (L->next == nullptr){
        return true;
    }
    return false;
}

int main(){
    LinkList L;
    // 不带头节点的单链表初始化
    InitList_without_head(L);
    printf("不带头结点的链表是否为空: %s\n", is_empty_without_head(L)?"是":"不是");

    LinkList L2;
    // 初始化带头结点的链表
    InitList_with_head(L2);
    printf("不带头结点的链表是否为空: %s", is_empty_with_head(L2)?"是":"不是");
}

