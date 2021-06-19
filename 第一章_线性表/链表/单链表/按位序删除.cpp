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

// 按照位序删除
/*
 * L 表示需要操作的链表
 * i表示要删除元素的位置
 * e表示删除的值，一定要用引用，要不然值带不回来
 * */
bool ListDelete(LinkList &L, int i, int &e){
    if (i < 1){             // 无效的位序
        return false;
    }
    Lnode *p;               // p指针要只要需要指向被删除节点的前一个节点
    int j = 0;              // 当前p指针的位置
    p = L;
    // 防止p为空，并且让p指向被删除节点的前一个节点
    while(p != nullptr && j < i-1){
        p = p->next;
        j++;
    }

    // 处理i值不合法
    if (p == nullptr){
        return false;
    }

    // p节点是尾节点
    if (p->next == nullptr){
        return false;
    }

    // 删除p节点后面的节点
    Lnode *q = p->next;             // 保存需要被删除的节点
    e = q->data;                    // 用e保存删除的返回值
    p->next = q->next;              // 将q节点断开
    free(q);                        // 释放q节点
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

    // 删除指定的位置
    int res = -1;
    ListDelete(L, 1, res);
    show_link_list_with_head(L);
    printf("被删除的值是%d", res);
    return 0;
}
