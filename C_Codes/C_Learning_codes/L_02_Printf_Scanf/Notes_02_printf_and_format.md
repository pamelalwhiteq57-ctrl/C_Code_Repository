# C 笔记 02

整理: 2026-11-16
这次讲一件事: printf 怎么打印, 以及 % 占位符.

## 先记这几句

1. printf 是 print formatted, f 就是 按格式打印. 带 f 才能用 %d 这类占位符.
2. printf 不会自动换行, 要换行就自己写 \n.
3. 写法是 printf("模板", 值1, 值2): 模板和值用逗号分开, 值按顺序填进占位符.
4. printf 直接把字打到屏幕上, 不产生字符串.

## printf 这个名字

print formatted, 意思是 按格式打印.

Python 里也有同一个 f:

```python
name = "小明"
print(f"hello {name}")      # f-string, 这个 f 也是 formatted
```

两边的 f 意思一样: 这句要按格式拼. 只是 C 贴在函数名上, Python 贴在字符串前面.

对照一下同族里不带 f 的:

- puts: 打印一整行, 但塞不进变量
- putchar: 只打印一个字符

## 不会自动换行

C 只管打我给的那些字符, 一个都不多打.

我写的这五行都带了 \n, 所以输出很整齐:

```c
printf("Hello\n");
printf("%d\n", 12);
printf("%f\n", 3.14);
printf("%c\n", 'A');
printf("%s\n", "abc");
```

```
Hello
12
3.140000
A
abc
```

要是去掉最后的 \n, 下一行就会贴着它打.

默认换行吗: Python 的 print 自带换行. C 的 printf 不换, 必须自己写 \n.
想不换行怎么写: Python 写 print(x, end=""). C 什么都不用写.

有趣的是两边反着来: Python 要额外写字才能不换行, C 要额外写字才能换行.

## 格式化写法

```c
printf("%d\n", 12);
printf("%s\n", "abc");
```

- 第一个参数是模板, 后面的是要填进去的值
- 模板里的 %d, %s 是占位符, 会被后面的值按顺序填上
- 占位符几个, 后面的值就该有几个

和 Python 的老式格式化对比:

写法: C 是 printf("%d", 12), Python 是 "%d" % 12.
值放在哪: C 放在逗号后面, Python 放在 % 的右边.
得到什么: C 直接打到屏幕上, Python 得到一个新的字符串.

关键差别: Python 的 % 会生成字符串, 所以能存起来:

```python
s = "%d" % 12        # s 是 "12"
```

C 的 printf 存不了, 它只负责往屏幕上打. 想把结果拼成字符串, 要用另一个函数 sprintf, 等我学到数组再说.

还有两点顺带的差别:

- 值多的时候: Python 的 print(1, 2) 会自动加空格, 输出 1 2; C 的 printf("%d %d", 1, 2) 不会, 空格要自己在模板里写
- Python 的 % 是老写法, 现在更常用 f-string; C 只有 %, 没有第二种选择

## printf 有返回值

printf 会返回一个整数: 这次打印了几个字符.

```c
int n = printf("abc");      /* 屏幕上打出 abc, n 变成 3 */
```

实测: printf("abc") 返回 3.

Python 的 print 打印完什么都不给我, 返回的是 None. C 这里给回一个数, 以后偶尔能派上用场.

## 四个最常用的占位符

%d 装整数 int, 实测打出 12.
%f 装小数 double, 实测打出 3.140000.
%c 装单个字符 char, 实测打出 A.
%s 装字符串, 实测打出 abc.

注意 %f 默认打印六位小数, 所以 3.14 变成 3.140000. 想只留两位:

```c
printf("%.2f\n", 3.14);      /* 输出 3.14 */
```

## 更多占位符, 按常用度排

%d 装 int, 实测 255.
%s 装字符串, 实测 abc.
%f 装 double, 六位小数, 实测 3.141590.
%c 装单个字符, 实测 A.
%lf 是 scanf 读 double 时用的, printf 里和 %f 一样.
%u 装 unsigned int, 实测 4000000000.
%x 是十六进制小写, 实测 ff. %X 是十六进制大写, 实测 FF.
%.2f 保留两位小数, 实测 3.14.
%ld 装 long, %lld 装 long long, 长整数用.
%e 是科学计数法, 实测 3.141590e+00.
%p 是地址, 等学指针, 实测 00000003da3ffcfc.
%o 八进制, 实测 377.
%g 自动选 %f 或 %e, 实测 3.14159.
%% 打印一个百分号, 实测 %.
%i 和 %d 完全一样, 实测 255.

## 宽度和精度

格式可以写成 %[宽度][.精度]类型.

%5d 占 5 格, 右对齐, 实测 [  255].
%-5d 占 5 格, 左对齐, 实测 [255  ].
%05d 占 5 格, 前面补 0, 实测 [00255].

## 类型和占位符对不上会怎样

我试过把 3.14 塞进 %d:

```
warning: format '%d' expects argument of type 'int', but argument 2 has type 'double' [-Wformat=]
    printf("%d\n", 3.14);
                ~^   ~~~~
                 |    |
                 int  double
                 %f
```

gcc 会提醒我, 还顺手标出这里该写 %f.

两个要点:

- C 是在编译时就提醒我, Python 要等运行到那行才报错
- 但它只是警告, 程序照样能编出来, 打印出来是乱码

## scanf 只说一句

scanf 是 scan formatted, 也是按格式读. 有一个地方和 printf 不能混: 读 double 必须写 %lf, 写成 %f 会读到垃圾值.

用法等我写到 scanf 再展开, 现在只需要知道它是配对的另一半.

## 我写的这个程序

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

两个小提示:

- 每行都写 \n, 输出才一行行分开. 少一个, 就和下一行贴在一起
- int main() 建议写成 int main(void), 括号里明确写 void 表示不接收参数
