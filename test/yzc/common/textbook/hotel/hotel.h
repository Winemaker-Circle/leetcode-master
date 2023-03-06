//
// Created by skyzc on 2022/8/6.
//

/* hotel.h -- 符号常量和 hotel.h 中的所有函数原型 */

#ifndef LEETCODE_MASTER_HOTEL_H
#define LEETCODE_MASTER_HOTEL_H

#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARTS "*************************************"

// 显示选择列表
int menu(void);
// 返回预定天数
int getnights(void);
// 根据费率、入住天数计算费用 并显示结果
void showprice(double rate,int nights);

#endif //LEETCODE_MASTER_HOTEL_H
