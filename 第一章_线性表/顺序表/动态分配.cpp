//
// Created by kaiven on 2021/5/28.
//

#include <stdio.h>
#include <stdlib.h>

#define InitSize 10         // 默认的最大长度

typedef struct {
    int *data;              // 指示动态分配数组的指针
    int MaxSize;            // 顺序表的最大容量
    int length;             // 顺序表的当前长度
}SeqList;

// 初始化顺序表
void InitList(SeqList &L){
    // 使用malloc函数申请一片连续的内存空间
    L.data = (int *) malloc(InitSize*sizeof(int));      // 给data分配初始的内存空间
    L.length = 0;               // 当前的表长为0
    L.MaxSize = InitSize;       // 表示表现在的最大长度
}

// 动态增加表的长度
void IncreaseSize(SeqList &L, int len){         // 表示需要增加的长度
    int *p = L.data;                            // 将原来的数据暂存起来
    L.data = (int *) malloc((L.MaxSize+len)*sizeof(int));
    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];                       // 将暂存的数据重新写入新区域
    }
    L.MaxSize = L.MaxSize + len;                // 顺序表的最大长度加len
    free(p);                                    // 释放原来的内存空间
}


int main(){
    SeqList L;              // 申明一个顺序表
    InitList(L);        // 初始化顺序表
    // 插入数据

    IncreaseSize(L, 5);
    printf("%d", L.MaxSize);
    return 0;
}

