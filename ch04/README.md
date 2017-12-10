[练习4.1](#)

>表达式5+10\*20/2的求值结果是多少？

    105

[练习4.2](#)

>根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序与添加括号前一致。  
(a) \*vec.begin()  
(b) \*vec.begin() + 1

    (a) *(vec.begin())
    (b) (*(vec.begin())) + 1

[练习4.3](#)

>C++语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下了余地。这种策略实际上是在代码生成效率和程序潜在缺陷之间进行了权衡，你认为这可以接受吗？请说出你的理由。

    可以接受，通过一定的方法可以强制让表达式的组合关系符合程序逻辑的要求。这种策略既提高了代码生成效率，同时也不会使得程序潜在缺陷不可避免

[练习4.4](#)

>在下面的表达式中添加括号，说明其求值的过程及最终结果。编写程序编译该（不加括号的）表达式并输出其结果验证之前的推断。

```cpp
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
```

```cpp
(((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2)
```

[练习4.5](#)

>写出下列表达式的求值结果。  
(a) -30 * 3 + 21 / 5  
(b) -30 + 3 * 21 / 5  
(c) 30 / 3 * 21 % 5  
(d) -30 / 3 * 21 % 4

    (a) -86
    (b) -18
    (c) 0
    (d) -2

[练习4.6](#)

>写出一条表达式用于确定一个整数时奇数还是偶数。

```cpp
n % 2 != 0 ? true : false //true代表奇数，false代表偶数
```

[练习4.7](#)

>溢出是何含义？写出三条将导致溢出的表达式。

溢出表示计算的结果超出类型所能表示的范围所产生的异常情况

```cpp
//1.
short short_value = 32767;
short_value ++;

//2.
short short_value1 = 32760;
short short_value2 = 10;
short_value = short_value1 + short_value2;

//3.
unsigned short ushort_value3 = 17000;
ushort_value3 \*= 2;
```

[练习4.8](#)

>说明在逻辑与、逻辑或及相等性运算中运算对象求值的顺序。

    都是从左向右，但是逻辑与和逻辑或有短路求值的策略
    
[练习4.9](#)

>解释在下面的if语句中条件部分的判断过程。

```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

    如果cp是空指针，则结果为false，判断结束，否则继续判断cp指向的字符是否是空字符，若是，则结果为false，否则结果为true，判断结束

[练习4.10](#)

>为while循环写一个条件，使其从标准库中读取整数，遇到42时则停止。

```cpp
int n;
while(cin >> n && n != 42)
```

[练习4.11](#)

>书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d。

```cpp
bool flag = (a>b) && (b>c) && (c>d)
```

[练习4.12](#)

>假设i、j和k是三个整数，说明表达式i!=j<k的含义。

    相当于i!=(j<k)，如果j<k则是i!=1，否则是i!=0

[练习4.13](#)

>在下述语句中，当赋值完成后i和d的值分别是多少？  
int i; double d;  
(a) d = i = 3.5;  
(b) i = d = 3.5;

    赋值运算符满足右结合律，所以:
    (a) i的值是3, d的值是3
    (b) i的值是3, d的值是3.5

[练习4.14](#)

>执行下述if语句后将发生什么情况？

```cpp
if (42 = i) // ...
if (i = 42) // ...
```

    第一个if不合法，字面值不能作为左值
    第二个if中的赋值语句返回i的值，即42，再将42转换成bool类型值，结果为true

[练习4.15](#)

>下面的赋值是非法的，为什么？应该如何修改？

```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

    pi是int\*类型，赋值运算符是右结合的，所以pi = 0返回类型是int\*，无法转换成int类型，可修改如下：

```cpp
double dval; int ival; int *pi = &dval;
dval = ival = *pi = 0;
```

[练习4.16](#)

>尽管下面的语句合法，但它们实际执行的行为可能和预期并不一样，为什么？应如何修改？  
(a) if (p = getPtr() != 0)  
(b) if (i = 1024)

    (a)的预期是通过p = getPtr()，然后判断p不是空指针，但是!=运算符的优先级比=高，所以和预期不同
    (b)的预期是判断i是否等于1024，但是使用赋值运算符=则将1024赋值给i，然后返回i的值并转换成bool类型（true），条件成立
    修改如下：
```cpp
if ((p = getPtr()) != 0)
if (i == 1024)
```

[练习4.17](#)

>说明前置递增运算符和后置递增运算符的区别。

    前置递增运算符和后置运算符都是将当前变量递增，不同的是前置递增运算符返回的是递增后的值，而后置递增运算符返回的是递增前的值

[练习4.18](#)

>如果第132页那个输出vector对象元素的while循环使用前置递增运算符，将得到什么结果？

    使用前置运算符将输出递增后的指针指向的对象，所以第一个元素不会输出，而且程序也会试图输出v.end()指向的对象，但是v.end()并不指向有意义的对象，对其进行解引用将会产生错误

[练习4.19](#)

>假设ptr的类型是指向int的指针、vec的类型是vector<int>、ival的类型是int，说明下面的表达式是何含义？如果有表达式不正确，为什么？应该如何修改？  
(a) ptr != 0 && *ptr++  
(b) ival++ && ival  
(c) vec[ival++] <= vec[ival]
                           
    (a) ptr不是空指针且ptr指向的值不是0
    (b) ival不是0且ival不是0，此表达式的预期应该是ival递增后的值也不是0，修改：++ival && ival
    (c) vec[ival] <= vec[ival]，此表达式的结果一直为true，此表达式的预期应该是下标ival+1对应的值不小于下标ival对应的值，修改：vec[++ival] <= vec[ival]
    
[练习4.20](#)

>假设iter的类型是vector<string>::iterator，说明下面的表达式是否合法。如果合法，表达式的含义是什么？如果不合法，错在何处？  
    (a) *iter++;  
    (b) (*iter)++;  
    (c) *iter.empty();  
    (d) iter->empty();  
    (e) ++*iter;  
    (f) iter++->empty();
    
    (a)合法，返回iter指向的值并且将iter递增
    (b)不合法，预期返回iter指向的值并且将其递增，但是string不可递增
    (c)不合法，*运算符的优先级低于.运算符，而empty()是vector的成员函数，不能使用迭代器调用
    (d)合法，->是成员运算符，string.empty()合法
    (e)不合法，预期递增iter指向的值并且将结果返回，但是string不可递增
    (f)合法，返回iter->empty()并且将iter递增

[练习4.21](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch04/ex4_21.cpp)

>编写一段程序，使用条件运算符从vector<int>中找到哪些元素的值是奇数，然后将这些奇数值翻倍。
    
```cpp
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    for(auto &e : vec)
    {
	    e%2==1?e*=2:e=e;
    }
    return 0;
}
```

[练习4.22](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch04/ex4_22.cpp)

>本书的示例程序将成绩划分成high pass、pass和fail三种，扩展该程序使其进一步将60分到75分之间的成绩设定为low pass。要求程序包含两个版本：一个版本只使用条件运算符；另外一个版本使用1个或多个if语句。哪个版本更容易理解？为什么？

```cpp
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int grade;
    cin>>grade;
	
    //版本1
    cout<<((grade>90)?"high pass":(grade>75)?"pass":(grade>=60)?"low pass":"fail")<<endl;
	
    //版本2
    if(grade>90)
    {
	    cout<<"high pass"<<endl;
    }
    if(grade<=90 && grade >75)
    {
	    cout<<"pass"<<endl;
    }
    if(grade<=75 && grade >=60)
    {
	    cout<<"low pass"<<endl;
    }
    if(grade<60)
    {
	    cout<<"fail"<<endl;
    }
    return 0;
}
```
    当然是第二个版本容易理解了。。。

[练习4.23](#)

>因为运算符的优先级问题，下面这条表达式无法通过编译。根据4.12节中的表（第147页）指出它的问题在哪里？应该如何修改？

```cpp
string s = "word";
string p1 = s + s[s.size() - 1] == 's' ? "" : "s";
```

    +运算符的优先级更高，所以先进行s + s[s.size() - 1]操作，而该表达式的值是string类型，不能和char类型值进行相等性判断，修改如下：

```cpp
string s = "word";
string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
```

[练习4.24](#)

>本节的示例程序将成绩划分成high pass、pass和fail三种，它的依据是条件运算符满足右结合律。加入条件运算符满足的是左结合律，求值过程将是怎样的？

先判断最
