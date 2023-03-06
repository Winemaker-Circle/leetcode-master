//
// Created by skyzc on 2022/8/5.
//
/* factor.c -- 使用循环和递归计算阶乘 */
#include "stdio.h"
long fact(int n);
long rfact(int n);

int main(){
    printf("This program calculates factorials.\n");
    printf("Enter a value in the range 0-12 (q to quit):\n");

    int num;
    while(scanf("%d",&num) == 1){
        if(num < 0){
            printf("No negative numbers,please.\n");
        } else if(num > 12){
            printf("Keep input under 13.\n");
        } else{
            printf("loop: %d factorial = %ld\n",num, fact(num));
            printf("recursion: %d factorial = %ld\n",num, rfact(num));
        }
        printf("Enter a value in the range 0-12 (q to quite):\n");
    }

    printf("Bye.\n");
    return 0;
}

long fact(int n){
    long ans;
    for (ans = 1; n>1;n--) {
        ans *= n;
    }
    return ans;
}
long rfact(int n){
    long ans;
    if(n>0){
        ans = n * rfact(n-1);
    } else{
        ans = 1;
    }
    return ans;
}