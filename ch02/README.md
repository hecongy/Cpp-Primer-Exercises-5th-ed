[练习2.1](#)

>类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？

int、long、long long和short都是带符号整数类型，区别在于它们的尺寸不同，可以表示的范围也不同，short->int->long->long long范围依次增大。  
float和double都是浮点类型，区别在于它们可表示的精度不同，double类型的精度比float类型的精度高。

[练习2.2](#)

>计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

利率：float，利率的有效位数一般在float能表示的范围之内；  
本金和付款：double，因为double类型的精度更高，允许的有效数字位数更高，而本金和付款可能具有多位有效数字。

[练习2.3](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_4.cpp)

>读程序写结果。  
unsigned u = 10, u2 = 42;  
std::cout << u2 - u << std::endl;  
std::cout << u - u2 << std::endl;  
int i = 10, i2 = 42;  
std::cout << i2 - i << std::endl;  
std::cout << i - i2 << std::endl;  
std::cout << i - u << std::endl;  
std::cout << u - i << std::endl;

结果分别是30、4294967264、32、-32、0、0。  
无符号整数超出表示范围，值为取模后的余数（P33），所以第二个运算的结果是4294967264；  
当一个算术表达式中既有无符号数又有int值时，int会被转换成无符号数（P34），所以最后两个运算的结果都是unsigned类型。

[练习2.4](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_4.cpp)

>编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

略

[练习2.5](#)

>指出下述字面值的数据类型并说明每一组内几种字面值的区别。  
(a) 'a', L'a', "a", L"a"  
(b) 10, 10u, 10L, 10uL, 012, 0xC  
(c) 3.14, 3.14f, 3.14L  
(d) 10, 10u, 10., 10e-2

(a) char, wchar_t, string, 宽字符string  
(b) int, unsigned, long, unsigned long, 八进制表示的int, 十六进制表示的int  
(c) double, float, long double  
(d) int, unsigned, double, double

[练习2.6](#)

>下面两组定义是否有区别，如果有，请叙述之：  
int month = 9, day = 7;  
int month = 09, day = 07;

有区别，第二组的定义表示为八进制，所以month的定义是不合法的，因为八进制的基数是8（9>8-1）。

[练习2.7](#)

>下述字面值表示何种含义？它们各自的数据类型是什么？  
(a) "Who goes with F\145rgus?\012"  
(b) 3.14e1L (c)1024f  (d)3.14L

(a)表示"Who goes with F\145rgus?\012"，类型是string  
(b)表示3.14，类型是long double  
(c)表示1024.0，类型是float  
(d)表示3.14，类型是long double

[练习2.8](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_8.cpp)

>请利用转义序列编写一段程序，要求先输出2M，然后转到新一行。修改程序使其先输出2，然后输出制表符，再输出M，最后转到新一行。

```
#include<iostream>
int main()
{
    std::cout<<"2M\n";
    std::cout<<"2\tM\n";
    return 0;
}
```
