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
```
unsigned u = 10, u2 = 42;  
std::cout << u2 - u << std::endl;  
std::cout << u - u2 << std::endl;  
int i = 10, i2 = 42;  
std::cout << i2 - i << std::endl;  
std::cout << i - i2 << std::endl;  
std::cout << i - u << std::endl;  
std::cout << u - i << std::endl;
```

    结果分别是30、4294967264、32、-32、0、0。  
    无符号整数超出表示范围，值为取模后的余数（P33），所以第二个运算的结果是4294967264；  
    当一个算术表达式中既有无符号数又有int值时，int会被转换成无符号数（P34），所以最后两个运算的结果都是unsigned类型。

[练习2.4](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_4.cpp)

>编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

```
#include<iostream>
int main()
{
    unsigned u=10,u2=42;
    std::cout<<u2-u<<std::endl;
    std::cout<<u-u2<<std::endl;
    
    int i=10,i2=42;
    std::cout<<i2-i<<std::endl;
    std::cout<<i-i2<<std::endl;
    
    std::cout<<i-u<<std::endl;
    std::cout<<u-i<<std::endl;
}
```

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
(b) 3.14e1L  
(c) 1024f  
(d) 3.14L

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

[练习2.9](#)

>解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。  
(a) std::cin >> int input_value;  
(b) int i = {3.14};  
(c) double salary = wage = 9999.99;  
(d) int i = 3.14;

    (a) 意图：定义int类型的input_value并从标准输入流输入，非法，类型名不可以出现在>>后，改正：  
        int input_value;  
        std::cin >> input_value;  
    (b) 含义：定义int类型的i并使用列表初始化向其赋值3.14，合法，但是会丢失信息，i的值为3  
    (c) 意图：定义double类型的salary和wage，并向它们赋值9999.99，非法，wage未定义，改正：  
        double salary = 9999.99, wage = 9999.99;  
    (d) 含义：定义int类型的i并使用拷贝初始化向其赋值3.14，合法，但是会丢失信息，i的值为3

[练习2.10](#)

>下列变量的初始值分别是什么？  
```
std::string global_str;  
int global_int;  
int main()  
{  
    int local_int;  
    std::string local_str;  
}
```

    global_str: 空字符串  
    global_int: 0  
    local_int: 未定义  
    local_str: 空字符串

[练习2.11](#)

>指出下面的语句是声明还是定义  
(a) extern int ix = 1024;  
(b) int iy;  
(c) extern int iz;

    (a)、(b)为定义，(c)为声明

[练习2.12](#)

>请指出下面的名字中哪些是非法的？  
(a) int double = 3.14;  
(b) int \_;  
(c) int catch-22;  
(d) int 1_or_2 = 1;  
(e) double Double = 3.14;

    (a)非法，不能使用关键字double作为变量名  
    (c)非法，标识符中只能包含字母、数字、下画线，不能含有"-"  
    (d)非法，标识符不能以数字开头

[练习2.13](#)

>下面程序中j的值是多少？  

```
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

    j的值为100。
    
[练习2.14](#)

>下面的程序合法吗？如果合法，它将输出什么？

```
int i = 100, sum = 0;
for (int i = 0; i != 10; i++)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

    合法，输出0-10的和，即55。
