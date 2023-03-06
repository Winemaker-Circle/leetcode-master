//
// Created by skyzc on 2022/8/5.
//
/* recur.c -- 递归演示 */
#include "stdio.h"
void up_and_down(int);

int main(void){
    int nurse = 22;
    int * ptr = &nurse;
    int val= *ptr;
    printf("1.P(enurse) = %d.\n",&nurse);
    printf("1.val = nurse = %d. P(ptr) = %p\n",val,ptr);
    nurse = 99;
    val= *ptr;
    printf("2.P(enurse) = %d.\n",*&nurse);
    printf("2.val = nurse = %d. P(ptr) = %p\n",val,ptr);
//    up_and_down(1);
}

void up_and_down(int n){
    printf("Level %d: n location %p.\n",n);
    if (n<4) {
        up_and_down(n+1);
    }
    printf("Level %d: n location %p.\n",n);
}