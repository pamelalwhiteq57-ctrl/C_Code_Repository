# C 笔记 01

2026-11-16

## 概念

include 就是把说明书抄到文件开头.
头文件只是名字清单, 不干活.
main 是入口, 系统来调它, 我不用自己调.
花括号划归属, 还管变量能活到哪儿.

## 程序骨架

```c
#include <stdio.h>              /* 抄说明书进来 */

int main(void){
    int a;
    scanf("%d", &a);
    printf("Hello World\n");
    printf("%d", a);
    return 0;
}
```

#include 那行没有分号, 它不是语句, 是预处理指令.
main 也是函数, 四件套: 返回类型, 名字, 括号, 大括号.
函数体里每句都要分号.

## include

编译之前, 把 stdio.h 的内容原样抄到这一行的位置.

少了它, printf 就不认识, 报:
error: implicit declaration of function 'printf'
意思是, 我不认识 printf 这个名字.

std 是 standard, io 是 input / output.

写在文件最上方.
用了 printf 或 scanf 就得写, 一个都不用可以不写.
换工具就换头文件: math.h, string.h, stdlib.h.

和 Python 的 import 比, import 是运行时去加载, include 是编译前复印一份.

## 头文件

里面是名字清单: 有什么东西, 长什么样, 不写怎么干活.
有分号没大括号, 就是声明.

比如这一行:
```c
int printf(const char *__format, ...);
```
能看出有这么个函数, 返回 int, 括号里收参数就够了, 里面的细节先不管.

抄进来的是说明书, 不是函数本身, printf 的代码早就编译好放在库里了.
只对这一个 .c 文件有用, 换个文件还得再写一遍.

Python 没有这一步, 因为它跑到那行才去找名字.

## 标准库

C 语言本身很小, 真正属于语言的只有语法和几十个关键字, 比如 int, if, return.
printf 不属于语言, 是别人写好放进标准库的.

语言: 语法, 我自己写的变量, if, for.
标准库: 一箱现成的函数, printf 和 scanf 在里面.
头文件: 那箱函数的目录.

程序变成 exe 的顺序:
我写 printf("hi").
编译器按说明书核对名字和参数.
链接器最后把库里真正的 printf 接进来.
所以我的 exe 里没有 printf 的源代码, 只有一条去库里哪找它的线索.

用过的是 stdio.h 里的两个: printf 输出, scanf 输入.
同一个头文件里还有几个基础的:
puts 打印一整行.
putchar 打印一个字符.
getchar 读一个字符.
这三个都不带 f, 所以不能格式化.

其他头文件知道有这回事就行:
stdio.h 管输入输出, 有 printf, scanf.
math.h 管数学, 有 sqrt.
string.h 管字符串, 有 strlen.
stdlib.h 管通用工具, 有 malloc, rand.
用到再查, 不用背. 查法是搜函数名加 cppreference, 或者直接看头文件.

## main

函数, 四件套齐全, 最前面的 int 是返回值类型.

和 Python 的 -> int 比, Python 的只是备注, 运行时不管.
C 的编译器要核对, 对不上就编译失败, 或者强行转换.

实测过, int 函数里写 return 3.9, 0 警告, 结果是 3, 等于悄悄做了 int(3.9).

为什么必须有 main, 因为操作系统先跑一段启动代码, 它最后一句就是调 main. 没有 main 就没有入口, 链接失败.

return 0 是给操作系统的, 0 表示正常, 非 0 表示出错.

语句不能写在函数外面, 外面只放声明和定义.
不是只有 main 里的代码会被编译, 所有函数都编, 只是没人调的不会执行.

## 花括号

划归属, 跟 Python 的缩进干同一件事, 但机制反着来.
Python 靠缩进, 错一格就报错. C 靠花括号, 缩进完全不管, 只给人看.

所以缩进可以随便, 但括号必须配对, 少一个报错会指到文件末尾.
写的时候先打左括号再打右括号, 然后往里填.

花括号还决定变量活到哪儿:
```c
int main(void) {
    int a = 1;              /* 活到 main 结束 */
    {
        int b = 2;          /* 活到这一层的右括号 */
    }
    printf("%d", a);        /* 可以 */
    printf("%d", b);        /* 不行, b 已经没了 */
}
```
在哪层括号里生的, 就活到那层右括号.
内层能用外层的, 外层不能用内层的.

Python 只有 def 建作用域, if 和 for 不建, 循环变量会漏出去. C 每个花括号都建.
