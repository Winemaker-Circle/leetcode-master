//
// Created by skyzc on 2022/8/6.
//
/* larger_of.c -- 取最大 */
#include "stdio.h"
void larger_of(double *,double *);

int main(void){
    double x = 45.6,y=99;
    printf("Originally x = %f and y = %f.\n",x,y);
    larger_of(&x,&y);
    printf("Originally x = %f and y = %f.\n",x,y);
}

void larger_of(double * n,double * m){
    printf("P(n)= %d.\n",(int)*n);
    if(*n > *m){
        *m = *n;
    } else{
        *n = *m;
    }
}