#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <string.h>
#include <algorithm>
#include <map>
#include <iterator>
#include <vector>
#include <ctype.h>
#include <array>
#include <numeric>
#include <stack>
#include <stdbool.h>

using namespace std;

int main(void)
{
#ifdef DEBUG_TEST_LYJ
    freopen("input.txt", "r", stdin);
#endif
 printf("%d\r\n", 12345678900);
 printf("%u\r\n", 12345678900); //无符号
 printf("%ld\r\n", 12345678900);
 printf("%lu\r\n", 12345678900);
 printf("%5d\r\n", 1234); //位数为3，不足左边补空格
 printf("%05d\r\n", 1234); //位数为3，不足左边补0
 printf("%o\r\n", 12); //无符号8进制
 printf("%x\r\n", 129); //无符号16进制
 printf("%X\r\n", 129); //无符号16进制大写
 printf("%04x\r\n", 129); // 位数为4，不足补零
 printf("%f\r\n", 12.345); // float
 printf("%lf\r\n", 12.3456); // double
 printf("%8.2f\r\n", 12.345); // 指定小数位数,不足左端补空格,5为包含小数的总列数
 printf("%-8.2f\r\n", 12.345); // 指定小数位数,不足右端补空格
 printf("%08.2f\r\n", 12.345); // 指定小数位数,不足左端补0
 printf("%08s\r\n", "123"); // 字符串,不足左端补0
 printf("%8s\r\n", "123"); // 字符串,不足左端补空格
 printf("%8p\r\n", 123); // 指针,不足左端补空格
    return 0;
}