//
// Created by kaiven on 2021/5/28.
//


#include <stdio.h>

#define MaxSize 10      // 定最大长度

typedef struct {
    int data[MaxSize];          // 用静态的"数组"存放数据元素
    int length;                 // 顺序表的当前长度
}Sqlist;                        // 顺序表的类型定义

// 基本操作---初始化一个顺序表
void InitList(Sqlist &L){
    for (int i = 0; i < MaxSize; ++i) {
        L.data[i] = 0;          // 将所有的元素设置为默认初始值（0）
    }
    L.length = 0;               // 顺序表初始长度为0
}

int main(){
    Sqlist L;                   // 声明一个顺序表
    InitList(L);            // 初始化一个顺序表

    // 执行结果
    printf("执行结果：\n");
    for (int i = 0; i < MaxSize; ++i) {
        printf("%d\n", L.data[i]);
    }
    return 0;
}