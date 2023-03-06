//
// Created by skyzc on 2022/8/5.
//
/* lesser.c -- 找出两个整数中较小的一个 */
#include "stdio.h"
int imin(int,int);
int what_if(int);

int main(void){
    int evil1,evil2;
    printf("Enter a pair of integers (q to quit): \n");
    while (scanf("%d %d",&evil1,&evil2) == 2){
        printf("The lesser of %d and %d is %d.\n",evil1,evil2, imin(evil1,evil2));
        printf("Enter a pair of integers (q to quit): \n");
    }
    printf("Bye.\n");

    printf("what_if result: %d\n", what_if(5));

    return 0;
}
int imin(int n,int m){
    return n<m?n:m;
}

int what_if(int n){
    double z = 100.0 / (double)n;
    return z;
}

