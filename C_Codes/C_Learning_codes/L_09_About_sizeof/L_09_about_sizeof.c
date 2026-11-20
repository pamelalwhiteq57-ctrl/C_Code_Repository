#include<stdio.h>
int main(){
    printf("%zu\n", sizeof(_Bool));
    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof(short));
    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(long));
    printf("%zu\n", sizeof(long long));
    printf("%zu\n", sizeof(float));
    printf("%zu\n", sizeof(double));
    printf("%zu\n", sizeof(long double));
    printf("sizeof(Expression):\n");
    int num = 100;
    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(num));//发现长度一致
    printf("Test again:\n");
    short s = 12;
    int b = 10;
    printf("%zu\n", sizeof(s = b + 1));//这里表达式其实没有计算，只看最终的s长度的结果，s是short，两个字节
    printf("s = %d\n", s);
    return 0;
}