//
// Created by kaiven on 2021/6/19.
//

#include "stdlib.h"
#include "stdio.h"

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

// 按位查找
/*
 * L    需要操作的链表
 * i    指定位置
 * return   指向节点的指针
 * */
Lnode* GetElem(LinkList L, int i){
    // i值不合法
    if (i < 0){
        return nullptr;
    }

    Lnode *p;               // p指针表示当前扫描到的节点
    int j = 0;              // 表示当前p的位置
    p = L;                  // 指向头结点
    // 循环找到第i个节点
    while (p != nullptr && j < i){
        p = p->next;
        j++;
    }

    return p;
}

// 按值查找
Lnode * LocateElem(LinkList L, int e){
    Lnode *p = L->next;
    while (p != nullptr && p->data != e){
        p = p->next;
    }
    return p;
}

// 计算表长
int Length(LinkList L){
    int len = 0;
    Lnode *p = L;
    while (p->next != nullptr){
        p = p->next;
        len++;
    }
    return len;
}

int main(){
    // 生成链表
    LinkList L;
    init_link_list_with_head(L);
    ListInsert_with_head(L, 1, 1);
    ListInsert_with_head(L, 2, 2);
    ListInsert_with_head(L, 3, 3);
    show_link_list_with_head(L);

    printf("第二个元素是%d\n", GetElem(L, 2)->data);

    printf("值是2的元素的的值%d\n", LocateElem(L, 2)->data);

    printf("当前链表的长度%d\n", Length(L));
    return 0;
}
