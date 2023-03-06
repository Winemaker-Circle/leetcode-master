//
// Created by skyzc on 2022/8/5.
//
/* binary.c -- 10进制整数输出 2进制 */
#include "stdio.h"
void to_binary(unsigned long n);

int main(void){
    unsigned long number;
    printf("Enter an integer (q to quite):\n");
    while(scanf("%lu",&number) == 1){
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n');
        printf("Enter an integer (q to quite):\n");
    }
    printf("Done.\n");
    return 0;
}
void to_binary(unsigned long n){
    int r;
    r = n % 2;
    if(n>=2){
        to_binary(n/2);
    }
    putchar(r==0?'0':'1');
}