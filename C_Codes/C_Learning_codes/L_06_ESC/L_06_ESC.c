#include<stdio.h>
int main(){
    printf("(Are u OK\?\?)\n");
    printf("%c\n", '\'');
    printf("%s\n", "\"");
    printf("%s\n", "\\");
    printf("\a\n");
    printf("abcdef\b\bqt\n");  //往前退光标位置,"f"被后面的替换，\f先不讲
    printf("abcdef\rxx\n");    //光标退到开头
    printf("a\tbc\tdef\tghi\tyyyyy\tw\n");
    return 0;
}