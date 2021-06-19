//
// Created by kaiven on 2021/6/19.
//

#include "stdlib.h"
#include "stdio.h"

#define MaxSize 10


typedef struct{
    int data;
    int next;
}SlinkList[MaxSize];

void init_static_link_list(SlinkList &L){
    for (int i = 0; i < MaxSize; ++i) {
        L[i].next = -2;         // 默认-2为无效值
    }
}

// 找到空闲的节点索引，返回-1说明没有空闲的节点
int find_free_index(SlinkList L){
    for (int i = 0; i < MaxSize; ++i) {
        if (L[i].next == -2){
            return i;
        }
    }
    return -1;
}


// 插入
void insert_static_link_list(SlinkList &L, int e){
    // 寻找尾结点
    int tail_index = -1;
    for (int i = 0; i < MaxSize; ++i) {
        if (L[i].next == -1){
            tail_index = i;
            break;
        }
    }

    int free_index = find_free_index(L);
    L[tail_index].next = free_index;
    L[free_index].data = e;
    L[free_index].next = -1;
}

void show_static_link_list(SlinkList L){
    for (int i = 0; i < MaxSize; ++i) {
        printf("%d  %d\n", L[i].data, L[i].next);
    }
}
int main(){
    SlinkList L;
    init_static_link_list(L);
    insert_static_link_list(L, 1);
    insert_static_link_list(L, 2);
    insert_static_link_list(L, 3);
    show_static_link_list(L);
    return 0;
}