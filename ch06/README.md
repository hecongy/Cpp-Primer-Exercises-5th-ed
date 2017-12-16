[练习6.1](#)

>实参和形参的区别是什么？

    实参是形参的初始值
    形参的作用域在函数内部

[练习6.2](#)

>请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？

```diff
//(a)
+ 返回值类型和实际返回的值不匹配
+ string f() {
- int f() {
    string s;
    //...
    return s;
}

//(b)
+ 缺少返回值类型
+ void f2(int i) { /* ... */}
- f2(int i) { /* ... */}

//(c)
+ 缺少一个{，且形参名不能重复
+ int calc(int v1, int v2) { /* ... */}
- int calc(int v1, int v1)   /* ... */}

//(d)
+ 函数体需要使用{}包围
+ double square(double x) { return x * x; }
- double square(double x) return x * x;
```

[练习6.3](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_3.cpp)

>编写你自己的fact函数，上机检查是否正确。

```cpp
#include<iostream>
using namespace std;
int fact(int val)
{
    int result = 1;
    while(val>1)
    {
	    result *= val;
	    val--;
	}
    return result;
}

int main()
{
    cout<<"Please input a integer: ";
    int val;
    cin>>val;
    cout<<val<<"! is "<<fact(val)<<endl;
}
```

[练习6.4](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_4.cpp)

>编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。

```cpp
#include<iostream>
using namespace std;
void printfact()
{
    int val;
    cout<<"Please input a integer: ";
    cin>>val;
    int result = 1;
    while(val>1)
    {
	    result *= val;
        val--;
	}
    cout<<val<<"! is "<<result<<endl;
}

int main()
{
    printfact();
}
```

[练习6.5](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_4.cpp)

>编写一个函数输出其实参的绝对值。

```cpp
#include<iostream>
using namespace std;
void absolute(int val)
{
    int result = val;
    if(val<0)
	    result = -val;
    cout<<"Absolute value of "<<val<<" is "<<result<<endl;
}

int main()
{	
    cout<<"Please input a integer: ";
    int val;
    cin>>val;
    absolute(val);
}
```

[练习6.6](#)

>说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。

形参和局部静态变量都是局部变量，局部变量包含形参和函数体内部定义的变量。形参在函数调用时由实参初始化，函数体内部定义的变量在函数控制路径经过变量定义语句时创建该对象，形参和函数体内部定义的变量都在函数结束时销毁。局部静态变量在程序执行路径第一次经过对象定义语句时初始化，并且到程序终止才被销毁

```cpp
int test(int val1) //val1,形参
{
    int val2 = 0; //函数体内部定义的变量
    static int val3 = 0; //局部静态变量
}
```

[练习6.7](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_7.cpp)

>编写一个函数，当它第一次被调用时返回0，以后每次调用返回值加1。

```cpp
#include<iostream>
using namespace std;
int get_value()
{
    static int val = 0;
    return val++;
}

int main()
{	
    cout<<"Press y to continue, n to stop."<<endl;
        char ch;
    while(cin>>ch)
    {
	if(ch=='y')
	    cout<<get_value()<<endl;
	if(ch=='n')
	    break;
    }		
}
```

[练习6.8](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_8.cpp)

>编写一个名为Chapter6.h的头文件，令其包含6.1节练习（第184页）中的函数声明。

```cpp
extern int fact(int val);
extern void printfact();
extern void absolute(int val);
```

[练习6.9]()

>编写你自己的fact.cc和factMain.cc，这两个文件都应该包含上一小节的练习中编写的Chapter6.h头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。

    略
    
[练习6.10](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_10.cpp)

>编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。

```cpp
#include<iostream>
using namespace std;
void swap(int *val1, int *val2)
{
    int tmp = *val1;
    *val1=*val2;
    *val2=tmp;
}

int main()
{
    cout<<"Please input two integers:"<<endl;
    int val1,val2;
    cin>>val1>>val2;
    cout<<"The input is: "<<val1<<", "<<val2<<endl;
    swap(&val1,&val2);
    cout<<"The output is: "<<val1<<", "<<val2<<endl;
    return 0;
}
```

[练习6.11](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_11.cpp)

>编写并验证你自己的reset函数，使其作用于引用类型的参数。

```cpp
#include<iostream>
using namespace std;
void reset(int &p)
{
    p=0;
}

int main()
{
    cout<<"Please input an integer:"<<endl;
    int val;
    cin>>val;
    cout<<"The input is: "<<val<<endl;
    reset(val);
    cout<<"The output is: "<<val<<endl;
    return 0;
}
```

[练习6.12](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_12.cpp)

>改写6.2.1节中的[练习6.10](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_10.cpp)（第188页）的程序，使用引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？

```cpp
#include<iostream>
using namespace std;
void swap(int &val1, int &val2)
{
    int tmp = val1;
    val1=val2;
    val2=tmp;
}

int main()
{
    cout<<"Please input two integers:"<<endl;
    int val1,val2;
    cin>>val1>>val2;
    cout<<"The input is: "<<val1<<", "<<val2<<endl;
    swap(val1,val2);
    cout<<"The output is: "<<val1<<", "<<val2<<endl;
    return 0;
}
```

引用更加方便，引用作为变量的别名，使用起来和变量一样

[练习6.13](#)

>假设T是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T)，另一个是void f(&T)。

    void f(T)是值传递，在函数内部改变T的值不会改变实参的值；void f(&T)是引用传递，在函数内部改变T的值会改变实参的值

[练习6.14](#)

>举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。

    应该是引用类型：实参不能拷贝，因此要使用引用避免拷贝，如IO类型
    不能是引用类型：无法将引用类型绑定到实参，如字面值常量

[练习6.15](#)

>说明find_char函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？

    s是引用类型是为了避免拷贝（string对象可能较大），s是常量引用是因为函数中不需要改变s的值
    occurs是引用是为了使用引用形参返回额外信息，occurs是普通引用是因为函数中需要改变occurs的值
    c不是引用类型是因为程序不需要通过引用类型返回额外信息
    如果s是普通引用，程序依然合法，但是函数中可以改变s的值；而且实参只能是string对象，不能是字面值常量
    如果occurs是常量引用，程序非法，因为函数中试图改变occurs的值

[练习6.16](#)

>下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。

```cpp
bool is_empty(string& s) { return s.empty(); }
```

    函数中没有改变s的值，因此形参可以使用常量引用
    再者，函数中如果没有其他操作，不如删掉，需要时直接调用s.empty()

[练习6.17](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_17.cpp)

>编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全都改成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？

```cpp
#include<iostream>
#include<string>
using namespace std;

//判断string对象中是否含有大写字母
bool contains_capital(const string &s)
{
    for(auto c:s)
    {
	if(isupper(c))
	    return true;
    }
    return false;
}

//把string对象全都改成小写形式
void tolower(string &s)
{
    for(auto &c:s)
    {
	c = tolower(c);
    }
}

int main()
{
    cout<<"Please input a string:"<<endl;
    string s;
    getline(cin,s);
    cout<<"The input string "<<(contains_capital(s)?"contains":"doesn't contain")<<" capital letter."<<endl;
    tolower(s);
    cout<<"The lower case version of input string is: "<<s<<endl;
    return 0;
}
```

[]
