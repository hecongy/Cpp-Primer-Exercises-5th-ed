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
