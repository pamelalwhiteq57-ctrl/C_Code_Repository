# C 笔记 03

2026-11-16

## 概念

关键字是语言保留的词, 不能当变量名, 也不能重新定义.
这个概念我在 Python 里就熟, 差别在内容, C 的关键字一大半和类型, 存储有关.
C17 一共 44 个, 其中 10 个以下划线开头, 平常几乎不碰.

## 分组

基本类型: char, int, short, long, float, double, void, _Bool.
类型修饰: signed, unsigned, const, static, extern, register, volatile, inline, restrict, auto, _Thread_local, _Atomic.
流程控制: if, else, switch, case, default, for, while, do, break, continue, goto, return.
自定义类型: struct, union, enum, typedef.
运算符式: sizeof, _Alignof, _Generic, 长得像函数, 其实是关键字.
编译期: _Static_assert, _Alignas, _Noreturn, 基本用不到.
复数: _Complex, _Imaginary.

## 和 Python 比

数量, Python 35 个, C 44 个.
类型相关的, Python 没有关键字管这个, 类型是函数 int(). C 一大半是类型和存储.
True / False, Python 是关键字. C17 里没有, 要 stdbool.h 才有 bool.
None / NULL, Python 的 None 是关键字. C 的 NULL 不是关键字, 是头文件里的宏.
违规后果, Python 报 SyntaxError, C 编译就报错.

两边都不能抢, 但 C 的关键字更贴近机器.

## 我的清单

```c
printf("Keywords in C:\n");
printf("auto, break, case, char, const, continue, default, do, double, else, enum, extern\n");
printf("float, for, goto, if, inline, int, long, register, restrict, return, short, signed\n");
printf("sizeof, static, struct, switch, typedef, union, unsigned, void, volatile, while\n");
printf("_Alignas, _Alignof, _Atomic, _Bool, _Complex, _Generic, _Imaginary, _Noreturn\n");
printf("_Static_assert, _Thread_local\n");
printf("Total: 44\n");
```

前 34 个按字母排, 下划线开头的 10 个单独放最后两行.
最后一行 Total: 44 是给自己对数的.

一开始这份清单只有 31 个, 漏了 char, inline, restrict 和 10 个下划线开头的, 补全才是 C17 的全部 44 个.
抄清单得数一遍, 差一个都不算全. char 最容易漏, 也最不该漏, 后面处理字符天天要用它.
