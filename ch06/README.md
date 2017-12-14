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
void fact()
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
    fact();
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
