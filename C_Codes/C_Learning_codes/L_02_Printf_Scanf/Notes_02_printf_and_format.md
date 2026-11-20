# C 笔记 02

2026-11-16

## 概念

printf 是 print formatted, f 就是按格式打印, 有 f 才能用 %d 这类占位符.
printf 不自动换行, 要换行自己写 \n.
写法是 printf("模板", 值1, 值2), 值按顺序填进占位符.
printf 直接把字打到屏幕上, 不产生字符串.

## 名字

print formatted, 按格式打印.
Python 里 f-string 的 f 也是 formatted:
```python
name = "小明"
print(f"hello {name}")
```
两边意思一样, 只是 C 的 f 贴在函数名上, Python 贴在字符串前面.

同族里不带 f 的:
puts 打印一整行, 塞不进变量.
putchar 只打印一个字符.

## 不自动换行

C 只管打我给的那些字符, 一个都不多打.

```c
printf("Hello\n");
printf("%d\n", 12);
printf("%f\n", 3.14);
printf("%c\n", 'A');
printf("%s\n", "abc");
```

输出:
```
Hello
12
3.140000
A
abc
```

去掉最后的 \n, 下一行就贴着它打.

Python 的 print 自带换行, 想不换行要写 end="".
C 的 printf 不换行, 想换行要自己写 \n.
两边正好反着来, Python 要额外写字才能不换行, C 要额外写字才能换行.

## 格式化写法

```c
printf("%d\n", 12);
printf("%s\n", "abc");
```
第一个参数是模板, 后面的是要填进去的值.
模板里的 %d, %s 是占位符, 按顺序被后面的值填上.
占位符几个, 后面的值就该有几个.

和 Python 的老式格式化比:
写法, C 是 printf("%d", 12), Python 是 "%d" % 12.
值放哪, C 放逗号后面, Python 放 % 右边.
得到什么, C 直接打到屏幕上, Python 得到一个新字符串.

Python 的 % 会生成字符串, 所以能存:
```python
s = "%d" % 12        # s 是 "12"
```
C 的 printf 存不了, 想拼成字符串要用 sprintf, 等学数组再说.

还有两点差别.
Python 的 print(1, 2) 自动加空格, C 的 printf("%d %d", 1, 2) 不加, 空格要写进模板.
Python 的 % 是老写法, 现在更常用 f-string, C 只有 %, 没有第二种.

## 返回值

printf 返回一个整数, 这次打印了几个字符.
```c
int n = printf("abc");      /* 屏幕上打出 abc, n 变成 3 */
```
实测 printf("abc") 返回 3.
Python 的 print 返回 None, C 这边给回一个数.

## 四个常用的

%d 装 int, 实测 12.
%f 装 double, 实测 3.140000.
%c 装单个字符, 实测 A.
%s 装字符串, 实测 abc.

%f 默认印六位小数, 所以 3.14 变成 3.140000. 想只留两位:
```c
printf("%.2f\n", 3.14);      /* 输出 3.14 */
```

## 其他占位符

%d 装 int, 实测 255.
%s 装字符串, 实测 abc.
%f 装 double, 六位小数, 实测 3.141590.
%c 装单个字符, 实测 A.
%lf 是 scanf 读 double 用的, printf 里和 %f 一样.
%u 装 unsigned int, 实测 4000000000.
%x 十六进制小写, 实测 ff.
%X 十六进制大写, 实测 FF.
%.2f 保留两位小数, 实测 3.14.
%ld 装 long, %lld 装 long long.
%e 科学计数法, 实测 3.141590e+00.
%p 地址, 等学指针, 实测 00000003da3ffcfc.
%o 八进制, 实测 377.
%g 自动选 %f 或 %e, 实测 3.14159.
%% 打印一个百分号, 实测 %.
%i 和 %d 一样, 实测 255.

## 宽度和精度

格式是 %[宽度][.精度]类型.
%5d 占 5 格右对齐, 实测 [  255].
%-5d 占 5 格左对齐, 实测 [255  ].
%05d 占 5 格前面补 0, 实测 [00255].

## 类型对不上

我把 3.14 塞进 %d, gcc 报:
```
warning: format '%d' expects argument of type 'int', but argument 2 has type 'double' [-Wformat=]
```
还顺手标出这里该写 %f.

C 在编译时就提醒, Python 要跑到那行才报错.
只是警告, 程序照样编得出来, 打出来是乱码.

## scanf

scanf 是 scan formatted, 按格式读.
和 printf 不能混的一处, 读 double 必须写 %lf, 写成 %f 会读到垃圾值.
用法等写到 scanf 再展开.

## 我的程序

```c
#include<stdio.h>
int main(){
    printf("Hello\n");
    printf("%d\n", 12);
    printf("%f\n", 3.14);
    printf("%c\n", 'A');
    printf("%s\n", "abc");
    return 0;
}
```
编译 0 警告, 输出就是上面那五行.
每行都写 \n 才一行行分开, 少一个就和下一行贴一起.
int main() 写成 int main(void) 更好, 括号里写 void 表示不收参数.
