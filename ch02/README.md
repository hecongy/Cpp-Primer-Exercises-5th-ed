[练习2.1](#)

>类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？

    int、long、long long和short都是带符号整数类型，区别在于它们的尺寸不同，可以表示的范围也不同，short->int->long->long long范围依次增大  
    float和double都是浮点类型，区别在于它们可表示的精度不同，double类型的精度比float类型的精度高

[练习2.2](#)

>计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

    利率：float，利率的有效位数一般在float能表示的范围之内  
    本金和付款：double，因为double类型的精度更高，允许的有效数字位数更高，而本金和付款可能具有多位有效数字

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

    结果分别是30、4294967264、32、-32、0、0  
    无符号整数超出表示范围，值为取模后的余数（P33），所以第二个运算的结果是4294967264  
    当一个算术表达式中既有无符号数又有int值时，int会被转换成无符号数（P34），所以最后两个运算的结果都是unsigned类型

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

    有区别，第二组的定义表示为八进制，所以month的定义是不合法的，因为八进制的基数是8（9>8-1）

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

    j的值为100
    
[练习2.14](#)

>下面的程序合法吗？如果合法，它将输出什么？

```
int i = 100, sum = 0;
for (int i = 0; i != 10; i++)
    sum += i;
std::cout << i << " " << sum << std::endl;
```



    合法，输出100 45
    
[练习2.15](#)

>下面的哪个定义是不合法的？为什么？  
(a) int ival = 1.01;  
(b) int &rval1 = 1.01;  
(c) int &rval2 = ival;  
(d) int &rval3;


    (b)不合法，因为引用类型的初始值必须是一个对象
    (d)不合法，因为引用类型必须初始化
    
[练习2.16](#)

>考查下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了什么样的操作？  
int i = 0, &r1 = i;  
double d = 0, &r2 = d;  
(a) r2 = 3.14159;  
(b) r2 = r1;  
(c) i = r2;  
(d) r1 = d;


    都合法
    (a)把3.14159赋值给r2指向的对象，即d，d的值变为3.14159
    (b)把r1指向的对象，即i的值0赋值给r2指向的对象，即d，d的值变为0.0
    (c)把r2指向的对象，即d的值0.0赋值给i，i的值仍为0
    (d)把d的值0.0赋值给r1指向的对象，即i，i的值仍为0
    

[练习2.17](#)

>执行下面的代码将输出什么结果？

```
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```


    10 10
    
[练习2.18](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_18.cpp)

>编写代码分别更改指针的值以及指针所指对象的值。

```
#include<iostream>
int main()
{
    int num1 = 5;
    int num2 = 6;
    int *p = &num1;
    std::cout<<"num1 change from "<<*p;
    *p = 7;
    std::cout<<" to "<<*p<<std::endl;
    
    std::cout<<"p pointers from "<<*p;
    p = &num2;
    std::cout<<" to "<<*p<<std::endl;
    return 0;
}
```

[练习2.19](#)

>说明指针和引用的主要区别

    引用只是对象的别名，不是对象，而指针是对象
    
[练习2.20](#)

>请叙述下面这段代码的作用。

```
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

    对i进行乘方运算
      
[练习2.21](#)

>请解释下述定义。在这些定义中有非法的吗？如果有，为什么？  
int i = 0;  
(a) double\* dp = &i;  
(b) int \*ip = i;  
(c) int \*p = &i;


    (a)非法，指针初始化必须严格匹配，不能将double类型指针指向int类型对象
    (b)非法，不能用int类型对象初始化int*类型对象
    
[练习2.22](#)

>假设p是一个int型指针，请说明下述代码的含义。

```
if (p) //...
if (*p) //...
```


    第一个if用来判断p是否是一个空指针
    第二个if用来判断p指向的对象的值是否为0
    
[练习2.23](#)

>给定指针p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。


    不能，参见https://www.zhihu.com/question/24331527
    
[练习2.24](#)

>在下面这段代码中为什么p合法而lp非法？

```
int i = 42;
void *p = &i;
long *lp = &i;
```


    指针初始化需要严格匹配，所以lp非法
    但是，void*是一种特殊的指针类型，可用于存放任意对象的地址，因此p合法
    
[练习2.25](#)

>说明下列变量的类型和值。  
(a) int\* ip, i, &r = i;  
(b) int i, \*ip = 0;  
(c) int\* ip, ip2;

    (a)ip: int\*类型，值为空；i: int类型，值由定义位置决定（默认初始化）；r: int&类型，绑定到i上
    (b)同上
    (c)ip: int\*类型，值为空；ip2: int类型，值由定义位置决定（默认初始化）
    
[练习2.26](#)

>下面哪些句子是合法的？如果有不合法的句子，请说明为什么？  
(a) const int buf;  
(b) int cnt = 0;  
(c) const int sz = cnt;  
(d) ++cnt; ++sz;


    (a)不合法，const修饰的变量需要初始化
    (d)不合法，const修饰的变量不可修改
    
[练习2.27](#)

>下面的哪些初始化是合法的？请说明原因。  
(a) int i = -1, &r = 0;  
(b) int \*const p2 = &i2;  
(c) const int i = -1, &r = 0;  
(d) const int \*const p3 = &i2;  
(e) const int \*p1 = &i2;  
(f) const int &const r2;  
(g) const int i2 = i, &r = i;


    (a)不合法，引用必须用对象初始化
    (b)合法，顶层const
    (c)合法，const修饰的引用可以使用字面值初始化
    (d)合法，可以将const int\*指向非const int对象
    (e)合法，可以将const int\*指向非const int对象
    (f)不合法，引用必须初始化
    (g)合法，可以使用非const int拷贝初始化const int，也可以将const int&绑定到非const int对象上
    
 
[练习2.28](#)

>说明下面的这些定义是什么意思，挑出其中不合法的。  
(a) int i, \*const cp;  
(b) int \*p1, \*const p2;  
(c) const int ic, &r = ic;  
(d) const int \*const p3;  
(e) const int \*p;

    (a)定义int型变量i和指向int型对象的顶层const指针cp
    (b)定义指向int型对象的指针p1和指向int型对象的顶层const指针p2
    (c)定义const int型变量ic和指向ic的int型引用，`不合法`，不能将非const引用指向const对象
    (d)定义指向const int型变量的顶层const指针p3，`不合法`，const指针必须初始化
    (e)定义指向const int型变量的底层const指针p
