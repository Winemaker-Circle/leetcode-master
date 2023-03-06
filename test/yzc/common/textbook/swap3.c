//
// Created by skyzc on 2022/8/6.
//
/* swap3.c -- 使用指针解决交换函数的问题 */
#include "stdio.h"
void interchange(int * u,int * v);

int main(void){
    int x = 5,y=10;
    printf("Originally x = %d and y = %d.\n",x,y);
    interchange(&x,&y);
    printf("Now x = %d and y = %d.\n",x,y);

    return 0;
}

void interchange(int * u,int * v){
    int temp = *u;
    *u = *v; // 等价于 x = y. * 是解引用 u 的值是一个地址（x的地址） 对一个地址解引用就是将其变为变量 x
    *v = temp;
}