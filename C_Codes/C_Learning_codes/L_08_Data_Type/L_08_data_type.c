#include <stdio.h>

int main()
{
    char c = 'A';
    short s = 100;
    int i = 2026;
    long l = 123456;
    long long ll = 1234567890123;
    float f = 3.14;
    double d = 3.1415926;
    long double ld = 3.14159265;
    _Bool b = 1;

    printf("%c\n", c);
    printf("%d\n", s);
    printf("%d\n", i);
    printf("%ld\n", l);
    printf("%lld\n", ll);
    printf("%f\n", f);
    printf("%lf\n", d);
    printf("%Lf\n", ld);
    printf("%d\n", b);
    return 0;
}