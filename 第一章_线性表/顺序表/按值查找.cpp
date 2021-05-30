//
// Created by kaiven on 2021/5/30.
//

#include "stdio.h"
#include "stdlib.h"

#define InitSize 10;

typedef struct {
    int* data;
    int maxsize;
    int length;
}Sqlist;

// 寻找指定元素的位序
int find_element_by_value(Sqlist &L, int val){
    for (int i = 0; i < L.length; ++i) {
        // 找到元素
        if (L.data[i] == val){
            return i+1;
        }
    }
    // 未找到元素
    return -1;
}

void init_table(Sqlist &L){
    // 不知道为什么下面这句话InitSize爆红
//    L.data = (int*) malloc(InitSize * sizeof(int));
    L.data = (int*) malloc(10 * sizeof(int));
    L.maxsize = InitSize;
    L.length = 0;
}

int main(){
    Sqlist L;
    // 初始化，给顺序表赋值
    init_table(L);
    for (int i = 0; i < 6; ++i) {
        L.data[L.length] = i+1;
        L.length++;
    }

    // 找到元素是2的位序
    printf("素是2的位序是%d", find_element_by_value(L, 2));
    return 0;
}

