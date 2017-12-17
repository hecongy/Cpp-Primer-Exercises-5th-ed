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

两个函数中形参的类型不同，因为操作类型不同，一个读（常量引用），一个写（非常量引用）

[练习6.18](#)

>为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。  
(a)名为compare的函数，返回布尔值，两个参数都是matrix类的引用。  
(b)名为change_val的函数，返回vector<int>的迭代器，有两个参数：一个是int，另一个是vector<int>的迭代器。
	
```cpp
//(a)比较两个matrix对象的大小
bool compare(matrix&,matrix&);

//(b)改变vector中某一位置（由int参数决定）元素的值
vector<int>::iterator change_val(int,vector<int>::iterator);
```

[练习6.19](#)

>假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。

```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

//(a)
calc(23.4, 55.1);

//(b)
count("abcda", 'a');

//(c)
calc(66);

//(d)
sum(vec.begin(), vec.end(), 3.8);
```

    (a)不合法，实参数目超过形参数目
    (b)合法
    (c)合法
    (d)合法

[练习6.20](#)

>引用参数什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？

    如果函数中不会改变参数的值，那么参数就应该是常量引用
    如果将原本应该是常量引用的参数设为了普通引用，在某些情况下无法使用函数，如参数是常量

[练习6.21](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_21.cpp)

>编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？

```cpp
#include<iostream>
using namespace std;
int compare(int val, int const* p)
{
    if(val>*p)
	return val;
    else
	return *p;
}

int main()
{
    cout<<"Please input two integers:"<<endl;
    int val1, val2;
    cin>>val1>>val2;
    cout<<"The larger one is: "<<compare(val1,&val2)<<endl;
    return 0;
}
```

    只读操作，指针的类型是底层const（指向的对象的值不变）

[练习6.22](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_22.cpp)

>编写一个函数，令其交换两个int指针。

    交换两个对象的值需要使用引用或指针实现，指针本身也是对象，所以使用指针的指针完成交换指针的功能

```cpp
#include<iostream>
using namespace std;

//交换两个int指针
void swap(int **pp1, int **pp2)
{
    int *tmp = *pp1;
    *pp1 = *pp2;
    *pp2 = tmp;
}

int main()
{
    cout<<"Please input two integers:"<<endl;
    int *p1, *p2, val1, val2;
    cin>>val1>>val2;
    p1=&val1;
    p2=&val2;
    swap(&p1,&p2);
    cout<<"The output is: "<<*p1<<", "<<*p2<<endl;
    return 0;
}
```

[练习6.23](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_23.cpp)

>参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j：

```cpp
int i = 0, j[2] = {0, 1};
```

```cpp
#include<iostream>
using namespace std;

void print(const int a[], size_t begin, size_t end)
{
    for(auto i = begin; i<end; i++)
    {
	cout<<a[i]<<endl;
    }
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print(&i, 0, 1);
    print(j, 0 ,2);
    return 0;
}
```

[练习6.24](#)

>描述下面这个函数的行为。如果代码中存在问题，请指出并改正。

```cpp
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

    print函数打印ia数组的前10个元素
    问题：如果ia的大小小于10，程序将会产生异常。
    应该使用管理指针形参的三种技术之一改正之，如：

```cpp
void print(const int ia[10], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << ia[i] << endl;
}
```

[练习6.25](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_25.cpp)

>编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。

    此处需要混用string对象和C风格字符串（第111页）

```cpp
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc!=3)
    {
	cout<<"Wrong parameter number."<<endl;
	return -1;
    }
	
    string s(strcat(argv[1],argv[2]));
    cout<<s<<endl;
	
    return 0;
}
```

[练习6.26](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_26.cpp)

>编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参的内容。

    注意，此处不能使用标准库的begin和end方法，因为argv作为参数传入后已经变成了指针类型char**

```cpp
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char * argv[])
{
    for(auto b = argv + 1; b < argv + argc; b++)
    {
	string s(*b);
	cout<<s<<endl;
    }
	
    return 0;
}
```

[练习6.27](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch06/ex6_27.cpp)

>编写一个函数，它的参数是initializer_list<int>类型的对象，函数的功能是计算列表中所有元素的和。
	
```cpp
#include<iostream>
#include<initializer_list>
using namespace std;
int sum(initializer_list<int> il)
{
    int sum = 0;
    for(const auto elem : il)
    {
	sum += elem;
    }
    return sum;
}

int main()
{
    cout<<sum({1,2,3,4,5})<<endl;
    return 0;
}
```

[练习6.28](#)

>在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？

    const string&类型，使用引用类型可以避免拷贝string对象，更高效

[练习6.29](#)

>在范围for循环中使用initializer_list对象时，应该将循环控制变量声明成引用类型吗？为什么？

    不需要，但是最好声明成引用类型，因为引用类型可以避免拷贝，使程序运行更加高效（第189页）

[练习6.30]
