# C 笔记 09

2026-11-19

## 概念

每种数据类型都有自己的长度.
长度就是它占几个字节.
类型长度不同, 能存的数的范围就不同.
长度是 C 才有的概念, Python 里没有这一层.

## 位和字节

一位就是一个 0 或者一个 1.
一个字节是八位.

## sizeof

sizeof 是关键字, 也是操作符, 专门用来算长度, 单位是字节.
写法有两种: sizeof(类型) 和 sizeof 表达式.
算出来的结果是 size_t 类型, 打印的时候用 %zu.

## 我跑出来的长度

```
sizeof(_Bool)       1
sizeof(char)        1
sizeof(short)       2
sizeof(int)         4
sizeof(long)        4
sizeof(long long)   8
sizeof(float)       4
sizeof(double)      8
sizeof(long double) 16
```

long 和 int 一样是 4, 所以 long 在 Windows 上并不比 int 能装更多.
float 和 int 一样是 4, 但它存的是小数, 不是整数.

## 表达式不参与计算

sizeof(int) 和 sizeof(num) 都打出 4, 说明变量和它的类型长度一样.
sizeof(s = b + 1) 打出 2, 而且后面 s 还是 12.
括号里那句赋值没有真的执行, sizeof 只看 s 是什么类型, 按类型算长度.

## 标准只保证顺序

C 标准保证的是这个顺序: 1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long).
具体是几个字节, 由系统自己定.
Windows 上 long 是 4, Linux 上 long 是 8, 同一个程序换个系统长度就可能变.
所以长度不能写死在心里, 要用的时候用 sizeof 问一下.

## 和 Python 比

Python 没有 sizeof, 也没有先挑类型这一步, int 自己按需要变长.
C 要我自己挑, 挑小了装不下, 就从另一头绕回去.
Python 里我不用担心"这个数会不会太大", C 里要担心.

## 结论

长度决定能装多大; 想知道长度就用 sizeof, 打印用 %zu.
长度是系统定的, 不是我背下来的一个数.
