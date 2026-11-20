#include <stdio.h>

int main(){
    int i = -1;
    unsigned int ui = 4294967295;
    printf("%d\n", i);           // -1
    printf("%u\n", i);           // 4294967295, 同一份数据按无符号看
    printf("%u\n", ui + 1);      // 0, 无符号加到顶再往上就回到 0

    short s = 32767;
    printf("%d\n", s + 1);       // 32768, short 先变成 int 再算, 装得下
    s = s + 1;
    printf("%d\n", s);           // -32768, 装回 short 才绕回去

    short t = -32768;
    t = t - 1;
    printf("%d\n", t);           // 32767, 最低点再退一格, 回到另一头

    char c = 200;
    unsigned char uc = 200;
    printf("%d\n", c);           // -56, 这台机器的 char 是有符号的
    printf("%u\n", uc);          // 200

    unsigned char u8 = 255;
    u8 = u8 + 1;
    printf("%u\n", u8);          // 0, 无符号的圈从 255 回到 0
    u8 = 0;
    u8 = u8 - 1;
    printf("%u\n", u8);          // 255, 0 再退一格是 255

    return 0;
}