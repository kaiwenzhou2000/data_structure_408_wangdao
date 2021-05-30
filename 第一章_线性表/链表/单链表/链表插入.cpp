//
// Created by kaiven on 2021/5/30.
//

#include "stdio.h"
#include "stdlib.h"


/*
 * intro
 *  链表的插入（带头结点和不带头结点
 *  链表的打印
 *  指定节点的前查和后插操作
 *
 * */

// 定义节点数据结构
typedef struct Lnode{
    int data;
    struct Lnode* next;
}Lnode, *LinkList;

// 初始化带头结点的链表
bool init_link_list_with_head(LinkList &L){
    L = (Lnode*) malloc(sizeof(Lnode));
    if (L == nullptr){
        return false;
    }
    L->next = nullptr;
    return true;
}

// 初始化不带头结点的链表
bool init_link_list_without_head(LinkList &L){
    L = nullptr;
    return true;
}

// 带头结点的按位序插入
// L 表示链表的表头地址
// i 表示想要插入的位置（位序）
// e表示要插入的元素
bool ListInsert_with_head(LinkList &L, int i, int e){
    // 判断i值是否合法
    if (i < 1){
        return false;
    }
    Lnode *p;                   // 指针p指向当前扫描到的节点
    int j = 0;                  // 当前p指向的第几个节点
    p = L;                      // 让指针p指向头结点，头结点是0号元素，不存储数据
    while (p!= nullptr && j < i-1){             // 循环找到第i-1个元素（i的前面一个元素）
        p = p->next;
        j++;
    }
    if (p == nullptr){          // i值不合法，超出数组的最大长度
        return false;
    }

    Lnode *s = (Lnode*) malloc(sizeof(Lnode));          // 创建一个新的节点
    s->data = e;
    // 下面的顺序不能变，要保证链表不断
    s->next = p->next;
    p->next = s;
    return true;
}

// 不带头结点的位序插入
// L 表示链表的表头地址
// i 表示想要插入的位置（位序）
// e表示要插入的元素
bool ListInsert_without_head(LinkList &L, int i, int e){
    if (i < 1){
        return false;
    }
    if (i == 1){                                            // 插入第一个元素与其他位置的操作不同（因为不带头结点）
        Lnode *s = (Lnode*) malloc(sizeof(Lnode));          // 创建一个节点用来存放e元素
        s->data = e;                                        // 给创建的节点赋值
        s->next = L;                                        // 将创建的节点指向第一个节点
        L = s;                                              // 将第一个节点重新指向刚刚创建的节点
        return true;
    }
    Lnode *p;           // 当前p指向当前扫描到的节点
    int j = 1;          // 表示当前p指向的位序，从1开始
    p = L;              // 将p节点指向第一个元素（注意不是头结点）
    while (p != nullptr && j < i-1){                // 循环到i-1个节点
        p = p->next;
        j++;
    }
    if (p == nullptr){          // p不存在，i越界
        return false;
    }
    // 下面开始插入操作
    Lnode *s = (Lnode*) malloc(sizeof(Lnode));
    s->data = e;
    // 下面两个顺序不能反
    s->next = p->next;
    p->next = s;
    return true;
}

// 展示带头结点的链表
void show_link_list_with_head(LinkList &L){
    Lnode *p = L->next;
    printf("带头结点的链表:");
    while (p != nullptr){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 展示不带头结点的链表
void show_link_list_without_head(LinkList &L){
    Lnode *p = L;
    printf("不带头结点的链表:");
    while (p != nullptr){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    // 带头结点的链表
    LinkList L;
    // 初始化带头结点的链表
    init_link_list_with_head(L);
    // 在位置1插入元素
    ListInsert_with_head(L, 1, 100);
    // 展示链表
    show_link_list_with_head(L);

    // 不带头结点的链表
    LinkList L2;
    // 初始化不带头结点的链表
    init_link_list_without_head(L2);
    // 在位置1插入元素
    ListInsert_without_head(L2, 1, 999);
    // 展示链表
    show_link_list_without_head(L2);
    return 0;
}
