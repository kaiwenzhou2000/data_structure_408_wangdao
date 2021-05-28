//
// Created by kaiven on 2021/5/28.
//

#ifndef DATA_STRUCTURE_SOURCE_CODE_顺序表_H
#define DATA_STRUCTURE_SOURCE_CODE_顺序表_H

#define MaxSize 10      // 定最大长度

// 定义顺序表结构
typedef struct {
    int data[MaxSize];          // 用静态的"数组"存放数据元素
    int length;                 // 顺序表的当前长度
}Sqlist;

// 静态分配顺序表
void InitList(Sqlist &L){
    for (int i = 0; i < MaxSize; ++i) {
        L.data[i] = 0;          // 将所有的元素设置为默认初始值（0）
    }
    L.length = 0;               // 顺序表初始长度为0
}

#endif //DATA_STRUCTURE_SOURCE_CODE_顺序表_H
