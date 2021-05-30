//
// Created by kaiven on 2021/5/30.
//

#include "stdio.h"
#include "stdlib.h"

#define InitSize 10             // 顺序表的初始长度

// 使用动态分配
typedef struct {
    int* data;                  // 指示动态分配数组的指针
    int Maxsize;                // 顺序表中最大的容量
    int lenth;                  // 顺序表的当前长度
}Sqlist;

int get_element_by_position(Sqlist L, int i){
    // 有一点小问题，这里没有考虑数组越界的问题
    return L.data[i-1];
}


// 初始化
void init_table(Sqlist &L){
    L.data = (int*) malloc(sizeof(int) * InitSize);
    L.lenth = 0;
    L.Maxsize = InitSize;
    for (int i = 0; i < InitSize; ++i) {
        L.data[i] = 0;
    }
}


int main(){
    Sqlist L;
    init_table(L);
    printf("现在顺序表的最大长度是%d\n", L.Maxsize);
    // 插入一个元素
    L.data[3] = -1;
    // 查找4号元素
    printf("四号元素是%d\n", get_element_by_position(L, 4));
    return 0;
}

