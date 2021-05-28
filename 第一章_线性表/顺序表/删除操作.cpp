//
// Created by kaiven on 2021/5/28.
//

#include "顺序表.h"
#include "stdio.h"

bool ListDelete(Sqlist &L, int i, int &e){
    if(i < 1 || i > L.length){                  // 判断i的范围是否有效
        return false;
    }
    e = L.data[i-1];                            // 将被删除的元素赋值给e
    for (int j = i; j < L.length; ++j) {        // 将第i个位置后的元素前移
        L.data[j-1] = L.data[j];
    }
    L.length--;                                 // 线性表长度减1
    return true;
}

int main(){
    Sqlist L;               // 申明一个顺序表
    InitList(L);        // 初始化顺序表
    // 插入元素
    for (int i = 0; i < 8; ++i) {
        L.data[i] = i+1;
        L.length++;
    }

    int e = -1;             // 将要删除的元素存入e中
    if (ListDelete(L, 3, e)){
        printf("已删除的第三个元素，删除的元素值为=%d\n", e);
    } else{
        printf("位序i不合法，删除失败\n");
    }
    return 0;
}