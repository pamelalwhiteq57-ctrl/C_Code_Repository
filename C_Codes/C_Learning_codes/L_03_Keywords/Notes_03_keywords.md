# C 笔记 03

整理: 2026-11-16
这次只有一件事: 关键字.

## 先记这几句

1. 关键字是语言保留的词, 不能拿来当变量名, 也不能重新定义.
2. 我在 Python 里早就熟悉这个概念了, 差别在内容: C 的关键字一大半是类型和存储相关的.
3. C17 一共 44 个, 其中 10 个以下划线开头, 平常几乎不碰.

## 按用途分组

基本类型: char, int, short, long, float, double, void, _Bool. 声明变量和函数的类型.
类型修饰: signed, unsigned, const, static, extern, register, volatile, inline, restrict, auto, _Thread_local, _Atomic. 说明变量怎么存, 能不能改, 放哪儿.
流程控制: if, else, switch, case, default, for, while, do, break, continue, goto, return. 分支, 循环, 跳出去.
自定义类型: struct, union, enum, typedef. 打包和起别名.
运算符式: sizeof, _Alignof, _Generic. 长得像函数, 其实是关键字.
编译期: _Static_assert, _Alignas, _Noreturn. 基本用不到.
几乎不用: _Complex, _Imaginary. 复数.

## 和 Python 对照

数量: Python 35 个, C 44 个.
类型相关的: Python 没有, 类型是函数 int(). C 一大半是类型和存储.
True / False: Python 是关键字. C17 里没有, 要 stdbool.h 才有 bool.
None / NULL: Python 的 None 是关键字. C 的 NULL 不是关键字, 是头文件里的宏.
违规后果: Python 报 SyntaxError, C 编译报错.

一句话: 两边都不能抢, 但 C 的关键字更贴近机器.

## 我程序里那份清单

```c
printf("Keywords in C:\n");
printf("auto, break, case, char, const, continue, default, do, double, else, enum, extern\n");
printf("float, for, goto, if, inline, int, long, register, restrict, return, short, signed\n");
printf("sizeof, static, struct, switch, typedef, union, unsigned, void, volatile, while\n");
printf("_Alignas, _Alignof, _Atomic, _Bool, _Complex, _Generic, _Imaginary, _Noreturn\n");
printf("_Static_assert, _Thread_local\n");
printf("Total: 44\n");
```

前 34 个按字母排, 下划线开头的 10 个单独放最后两行. 最后那行 Total: 44 是给自己核对的.

一开始这份清单只有 31 个, 漏了 char, inline, restrict 和 10 个下划线开头的. 补全后才是 C17 的全部 44 个.

这件事本身值得记一句: 抄清单的时候一定要数一遍, 差一个都不算全. char 是最容易漏也最不该漏的那个, 我后面处理字符天天要用它.
