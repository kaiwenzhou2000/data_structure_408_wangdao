//
// Created by kaiven on 2021/5/30.
//


#include "stdio.h"

#define MaxSize 10      // 定最大长度

typedef struct {
    int data[MaxSize];          // 用静态的"数组"存放数据元素
    int length;                 // 顺序表的当前长度
}Sqlist;                        // 顺序表的类型定义


// 插入指定位序的元素
bool ListInsert(Sqlist &L, int i, int e){
    if(i < 1 || i > L.length + 1){          // 判断i的范围是否有效
        return false;
    }
    if(L.length >= MaxSize){                // 当前存储空间已满，不能插入
        return false;
    }
    for (int j = L.length; j >= i; j--) {       // 将第i个元素之后的元素后移（从最后一个元素开始移动）
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;                        // 在位置i处放入e
    L.length++;
    return true;
}

// 基本操作---初始化一个顺序表
void InitList(Sqlist &L){
    for (int i = 0; i < MaxSize; ++i) {
        L.data[i] = 0;          // 将所有的元素设置为默认初始值（0）
    }
    L.length = 0;               // 顺序表初始长度为0
}

int main() {
    Sqlist L;
    InitList(L);
    // 测试
    // test1：向1号元素插入数据
    printf("%d\n", ListInsert(L, 1, 100));
    // test2：向2号元素插入数据
    printf("%d\n", ListInsert(L, 2, 100));
    // test3：向1000号元素插入数据
    printf("%d\n", ListInsert(L, 1000, 100));
    // test4：向-1号元素插入数据
    printf("%d\n", ListInsert(L, -1, 100));
}