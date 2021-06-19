//
// Created by kaiven on 2021/6/19.
//

#include "stdio.h"
#include "stdlib.h"


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

// 指定节点删除（这里p节点不能尾节点）
bool DeleteNode(Lnode *p){
    if (p == nullptr){
        return false;
    }

    Lnode *q = p->next;                 // q指向p的后一个节点
    p->data = p->next->data;            // 将后继节点交换数据域
    p->next = q->next;                  // 将q节点从链表中断开
    free(q);
    return true;
}

int main(){
    // 生成链表
    LinkList L;
    init_link_list_with_head(L);
    ListInsert_with_head(L, 1, 1);
    ListInsert_with_head(L, 2, 2);
    ListInsert_with_head(L, 3, 3);
    show_link_list_with_head(L);

    // 删除第二个节点
    DeleteNode(L->next->next);
    show_link_list_with_head(L);
    return 0;
}