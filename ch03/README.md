[练习3.1](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_1.cpp)

>使用恰当的using声明重做[1.4.1节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/README.md)（第11页）和[2.6.2节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/README.md)（第67页）的练习。

    以1.4.1节练习为例：
```cpp
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void ex1_9()
{
    int sum = 0;
    int i = 50;
    while(i<=100)
    {
	sum+=i;
	i++;
    }
    cout<<"The sum of numbers from 50 to 100 is "<<sum<<endl;
}

void ex1_10()
{
    cout<<"Numbers from ten down to zero are:"<<endl;
    int i = 10;
    while(i>=0)
    {
	std::cout<<i<<std::endl;
	i--;
    }
}

void ex1_11()
{
    cout<<"Please input two integers:"<<endl;
    int val1, val2;
    cin>>val1>>val2;
    if(val1<val2)
    {
	int swap = val1;
	val1=val2;
	val2=swap;
    }
    cout<<"Numbers in the range of "<<val1<<" and "<<val2<<" are:"<<endl;
    while(val1>=val2)
    {
	cout<<val1<<endl;
	val1--;
    }
} 

int main()
{
    ex1_9();
    ex1_10();
    ex1_11();
    return 0;
}
```

[练习3.2](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_2.cpp)

>编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。

```cpp
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    //一次读入一整行
    string line;
    getline(cin,line);
    cout<<"The line is: "<<line<<endl;
	
    //一次读入一个词
    string word;
    int count = 0;
    while(cin>>word)
    {
	count++;
    }
    cout<<count<<" words are input."<<endl;
    return 0;
}
```

[练习3.3](#)

>请说明string类的输入运算符和getline函数分别是如何处理空白字符的。

    string类的输入运算符默认将空白字符作为分隔符；getline函数则将空白字符当作一般字符处理
    
[练习3.4](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_4.cpp)

>编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不想等，输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。

```cpp
#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

//输出较大的字符串
void biggerone()
{
    cout<<"Please input two strings: "<<endl;
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    if(s1==s2)
    {
        cout<<"Two input strings are same."<<endl;
    }
    else if(s1>s2)
    {
        cout<<"The bigger input string is: "<<s1<<endl;
    }
    else
    {
        cout<<"The bigger input string is: "<<s2<<endl;
    }
}

//输出较长的字符串
void longerone()
{
    cout<<"Please input two strings: "<<endl;
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    if(s1.size()==s2.size())
    {
        cout<<"Two input strings' length are same."<<endl;
    }
    else if(s1.size()>s2.size())
    {
        cout<<"The longer input string is: "<<s1<<endl;
    }
    else
    {
        cout<<"The longer input string is: "<<s2<<endl;
    }
}
int main()
{
    biggerone();
    longerone();
    return 0;
}
```

[练习3.5](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_5.cpp)

>编写一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分隔开来。

```cpp
#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

//拼接字符串
void concatenate()
{
    cout<<"Please input strings: "<<endl;
    string s1, s2;
    getline(cin,s1);
    while(getline(cin,s2))
    {
	s1 += s2;
    }
    cout<<"The result is: "<<s1<<endl;
}

//用空格拼接字符串
void concatenatewithspace()
{
    cout<<"Please input strings: "<<endl;
    string s1, s2;
    getline(cin,s1);
    while(getline(cin,s2))
    {		
	s1 += s2;
	s1 += " ";
    }
    cout<<"The result is: "<<s1<<endl;
}
int main()
{
    concatenate();
    concatenatewithspace();
    return 0;
}
```

[练习3.6](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_6.cpp)

>编写一段程序，使用范围for语句将字符串内的所有字符用X代替。

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"Please input a string:"<<endl;
    string s;
    getline(cin,s);
    for(auto &c:s)
    {
	c='X';
    }
    cout<<"The result is: "<<s<<endl;
    return 0;
}
```


[练习3.7](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_7.cpp)

>就上一题完成的程序而言，如果将循环控制变量的类型设为char将发生什么？先估计一下结果，然后实际编程进行验证。

    字符串不会改变，因为范围for的循环控制变量是拷贝赋值的，所以不会改变字符串：

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"Please input a string:"<<endl;
    string s;
    getline(cin,s);
    for(char c:s) //拷贝赋值  
    {
	c='X';
    }
    cout<<"The result is: "<<s<<endl;
    return 0;
}
```

[练习3.8](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_8.cpp)

>分别用while循环和传统的for循环重写第一题的程序，你觉得哪种形式更好呢？为什么？

    范围for更简洁，不需要去控制下标：

```cpp
#include<iostream>
#include<string>
using namespace std;

//while循环
void whileloop()
{
    cout<<"Please input a string:"<<endl;
    string s;
    getline(cin,s);
	
    decltype(s.size()) i = 0;
    while(i<s.size())
    {
	s[i] = 'X';
	i++;
    }
    cout<<"The result is: "<<s<<endl;
}

//传统for循环
void traditionalforloop()
{
    cout<<"Please input a string:"<<endl;
    string s;
    getline(cin,s);
	
    for(decltype(s.size()) i=0;i<s.size();i++)
    {
	s[i] = 'X';
    }
    cout<<"The result is: "<<s<<endl;
}
int main()
{
    whileloop();
    traditionalforloop();
    return 0;
}
```

[练习3.9](#)

>下面的程序有何作用？它合法吗？如果不合法，为什么？

```cpp
string s;
cout << s[0] <<endl;
```

    不合法，s默认初始化是空字符串，长度为0，不能访问第一个字符s[0]
    
[练习3.10](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_10.cpp)

>编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"Please input a string:"<<endl;
    string s;
    string result;
    getline(cin,s);
    for(char c:s)
    {
	if(!ispunct(c))
	    result+=c;
    }
    cout<<"The result is: "<<result<<endl;
    return 0;
}
```

[练习3.11](#)

>下面的范围for语句合法吗？如果合法，c的类型是什么？

```cpp
const string s = "Keep out!";
for (auto &c : s) { /*...*/ }
```

    合法，c的类型是const char&

[练习3.12](#)

>下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。  
(a) vector<vector<int>> ivec;  
(b) vector<string> svec = ivec;  
(c) vector<string> svec(10, "null");
	
    (a)正确，ivec不含任何元素
    (b)不正确，svec的元素是string对象，不是vector<int>
    (c)正确，svec有10个相同的元素"null"
    
[练习3.13](#)

>下列的vector对象各包含多少个元素？这些元素的值分别为多少？  
(a) vector<int> v1;  
(b) vector<int> v2(10);  
(c) vector<int> v3(10,42);  
(d) vector<int> v4{10};  
(e) vector<int> v5{10,42};  
(f) vector<string> v6{10};  
(g) vector<string> v7{10, "hi"};
	
    (a) 0个元素
    (b) 10个元素，都是0
    (c) 10个元素，都是42
    (d) 1个元素，42
    (e) 2个元素，10、42
    (f) 10个元素，都是空字符串
    (g) 10个元素，都是"hi"

[练习3.14](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_14.cpp)

>编写一段程序，用cin读入一组整数并把它们存入一个vector对象。

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout<<"Please input integers:"<<endl;
    vector<int> ivec;
    int i;
    while(cin>>i)
    {
	ivec.push_back(i);
    }
    cout<<"All integers you input are:"<<endl;
    for(auto m:ivec)
    {
	cout<<m<<endl;
    }
    return 0;
}
```

[练习3.15](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_15.cpp)

>改写上题程序，不过这次读入的是字符串。

```cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    cout<<"Please input strings:"<<endl;
    vector<string> svec;
    string s;
    while(getline(cin,s))
    {
	svec.push_back(s);
    }
    cout<<"All strings you input are:"<<endl;
    for(auto m:svec)
    {
	cout<<m<<endl;
    }
    return 0;
}
```

[练习3.16](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_16.cpp)

>编写一段程序，把[练习3.13](#)中vector对象的容量和具体内容输出出来。检验你之前的回答是否正确，如果不对，回过头重新学习3.3.1节（第87页）直到弄明白错在何处为止。

```cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10,"hi"};
	
    cout<<"v1 contains "<<v1.size()<<" elements. They are:"<<endl;
    for(auto e:v1)
    {
	cout<<e<<endl;
    }
	
    cout<<"v2 contains "<<v2.size()<<" elements. They are:"<<endl;
    for(auto e:v2)
    {
	cout<<e<<endl;
    }
	
    cout<<"v3 contains "<<v3.size()<<" elements. They are:"<<endl;
    for(auto e:v3)
    {
	cout<<e<<endl;
    }
	
    cout<<"v4 contains "<<v4.size()<<" elements. They are:"<<endl;
    for(auto e:v4)
    {
	cout<<e<<endl;
    }
	
    cout<<"v5 contains "<<v5.size()<<" elements. They are:"<<endl;
    for(auto e:v5)
    {
	cout<<e<<endl;
    }
	
    cout<<"v6 contains "<<v6.size()<<" elements. They are:"<<endl;
    for(auto e:v6)
    {
	cout<<e<<endl;
    }
	
    cout<<"v7 contains "<<v7.size()<<" elements. They are:"<<endl;
    for(auto e:v7)
    {
	cout<<e<<endl;
    }
	
    return 0;
}
```

[练习3.17](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_17.cpp)

>从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改写为大写形式。输出改变后的结果，每个词占一行。

    首先遍历所有单词，对于每个单词，遍历所有字符

```cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string word;
    vector<string> words;
    cout<<"Please input word sequence:"<<endl;
    while(cin>>word)
    {
	words.push_back(word);
    }
	
    for(auto &e:words)
    {
	for(auto &c:e)
	{
	    c = toupper(c);
	}		
    }
	
    cout<<"The result is:"<<endl;
	
    for(auto e:words)
    {
	cout<<e<<endl;
    }
	
    return 0;
}
```

[练习3.18](#)

>下面的程序合法吗？如果不合法，你准备怎么修改？

```cpp
vector<int> ivec;
ivec[0] = 42;
```

    不合法，ivec中没有元素，所以不能使用下标运算符访问其第一个元素，修改：

```cpp
vector<int> ivec(1);
ivec[0] = 42;
```

[练习3.19](#)

>如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请列举出三种不同的实现方法。哪种方法更好呢？为什么？

```cpp
//1.
vector<int> ivec(10,42);

//2.
vector<int> ivec(10);
for(int i=0; i<10; i++)
{
    ivec[i] = 42;
}

//3.
vector<int> ivec;
for(int i=0; i<10; i++)
{
    ivec.push_back(42);
}
```

    三种方法都能满足要求，第一种更好，直接初始化，不需要额外的下标访问或者push_back操作
    
[练习3.20](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_20.cpp)

>读入一组整数并把它们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。

    设置两个下标标志：b和e分别代表vector的首尾指针
```cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int i;
    vector<int> ivec;
    cout<<"Please input integer sequence:"<<endl;
    while(cin>>i)
    {
	ivec.push_back(i);
    }
	
    decltype(ivec.size()) b = 0;
    auto e = ivec.size()-1;
	
    cout<<"Sum of adjacent members are:"<<endl;
    while(b+1<=e)
    {
	cout<<ivec[b]+ivec[b+1]<<endl;
	b=b+2;
    }
    if(b==e)
        cout<<ivec[e]<<endl;
	
    b=0;
    cout<<"Sum of symmetrical members are:"<<endl;
    while(b<e)
    {
	cout<<ivec[b]+ivec[e]<<endl;
	b++;
	e--;
    }
    if(b==e)
	cout<<ivec[e]<<endl;
	
    return 0;
}
```

[练习3.21](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_21.cpp)

>请使用迭代器重做3.3.3节（第94页）的[第一个练习](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_16.cpp)。

```cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10,"hi"};
	
    cout<<"v1 contains "<<v1.size()<<" elements. They are:"<<endl;
    for(auto it=v1.begin();it<v1.end();it++)
	cout<<*it<<endl;
	
    cout<<"v2 contains "<<v2.size()<<" elements. They are:"<<endl;
    for(auto it=v2.begin();it<v2.end();it++)
	cout<<*it<<endl;
	
    cout<<"v3 contains "<<v3.size()<<" elements. They are:"<<endl;
    for(auto it=v3.begin();it<v3.end();it++)
	cout<<*it<<endl;
	
    cout<<"v4 contains "<<v4.size()<<" elements. They are:"<<endl;
    for(auto it=v4.begin();it<v4.end();it++)
	cout<<*it<<endl;
	
    cout<<"v5 contains "<<v5.size()<<" elements. They are:"<<endl;
    for(auto it=v5.begin();it<v5.end();it++)
	cout<<*it<<endl;
	
    cout<<"v6 contains "<<v6.size()<<" elements. They are:"<<endl;
    for(auto it=v6.begin();it<v6.end();it++)
	cout<<*it<<endl;
	
    cout<<"v7 contains "<<v7.size()<<" elements. They are:"<<endl;
    for(auto it=v7.begin();it<v7.end();it++)
	cout<<*it<<endl;
	
    return 0;
}
```

[练习3.22](#)

>修改之前那个输出text第一段的程序，首先把text的第一段全都改成大写形式，然后再输出它。

    遍历每一行的所有字符并转换
```cpp
for(auto it = text.begin(); it != text.end() && !it->empty(); ++it)
{
    for(auto &c: *it)
    	c = toupper(c);
    cout << *it <<endl;
}
```

[练习3.23](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_23.cpp)

>编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> ivec(10);
    for(int i=0; i<10; i++)
    {
	ivec[i] = i;
    }
	
    cout<<"The origin vector is:"<<endl;
    for(auto it = ivec.begin(); it!=ivec.end(); it++)
    {
	cout<<*it<<endl;
	*it *= *it;
    }
	
    cout<<"The changed vector is:"<<endl;
    for(auto it = ivec.begin(); it!=ivec.end(); it++)
    {
	cout<<*it<<endl;
    }
    return 0;
}
```

[练习3.24](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_24.cpp)

>请使用迭代器重做3.3.3节（第94页）的[最后一个练习](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_20.cpp)。

    下标标志替换为迭代器（注意，end()是尾后迭代器）
```cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int i;
    vector<int> ivec;
    cout<<"Please input integer sequence:"<<endl;
    while(cin>>i)
    {
	ivec.push_back(i);
    }
	
    auto b = ivec.begin();
    auto e = ivec.end()-1;
	
    cout<<"Sum of adjacent members are:"<<endl;

    while(b+1<=e)
    {
	cout<<*b + *(b+1)<<endl;
	b=b+2;
    }
    if(b==e)
	cout<<*e<<endl;
	
    b=ivec.begin();
    cout<<"Sum of symmetrical members are:"<<endl;
    while(b<e)
    {
	cout<<*b + *e<<endl;
	b++;
	e--;
    }
    if(b==e)
	cout<<*e<<endl;
	
    return 0;
}
```

[练习3.25](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_25.cpp)

>3.3.3节（第93页）划分分数段的程序是使用下标运算符实现的，请利用迭代器修改该程序并实现相同的功能。

```cpp
#include<iostream>
#include<vector>
using namespace std;

//原程序
void index()
{
    //以10分为一个分数段统计成绩的数量：0~9, 10~19, ..., 90~99, 100
    vector<unsigned> scores(11,0); //11个分数段，全部初始化为0
    unsigned grade;
    while(cin >> grade){           //读取成绩
	if(grade <= 100)           //只处理有效的成绩
	    ++scores[grade/10];    //将对应分数段的计数值加1 
    }
	
    cout<<"Statistics are:"<<endl;
    for(int i = 0; i < 11; i ++)
    {
	if(i!=10)
	{
	    cout<< i*10 <<"~"<<i*10+9<<": "<<scores[i]<<endl;
	}
	else
	{
	    cout<< "100: "<<scores[i]<<endl;
	}
    }
}

//迭代器版本
void iteration()
{
    //以10分为一个分数段统计成绩的数量：0~9, 10~19, ..., 90~99, 100
    vector<unsigned> scores(11,0); //11个分数段，全部初始化为0
    unsigned grade;
    while(cin >> grade){                       //读取成绩
	if(grade <= 100)                       //只处理有效的成绩
            ++(*(scores.begin()+grade/10));    //将对应分数段的计数值加1 
    }
	
    cout<<"Statistics are:"<<endl;
    for(auto b = scores.cbegin(); b!=scores.cend(); b++)
    {
	if(b!=scores.cend()-1)
	{
	    cout<< (b-scores.cbegin())*10 <<"~"<<(b-scores.cbegin())*10+9<<": "<<*b<<endl;
	}
	else
	{
	    cout<< "100: "<<*b<<endl;
	}
    }
}

int main()
{
    iteration();
    return 0;
}
```

[练习3.26](#)

>在100页的二分搜索程序中，为什么用的是 mid = beg + (end - beg) /2，而非 mid = (beg + end) /2;?

    1.迭代器没有+运算
    2.相加可能导致溢出

[练习3.27](#)

>假设txt_size是一个无参数的函数，它的返回值是int。请回答下列哪个定义是非法的？为什么？  
unsigned buf_size = 1024;  
(a) int ia\[buf_size];  
(b) int ia\[4 * 7 -14];  
(c) int ia\[txt_size()];  
(d) char st\[11] = "fundamental";

    (a)非法，buf_size不是常量表达式
    (b)合法
    (c)如果txt_size()是constexpr则合法，否则非法
    (d)非法，"fundamental"有12个元素（包括表示字符串结束的空字符）
    
[练习3.28](#)

>下列数组中元素的值是什么？

```cpp
string sa[10];
int ia[10];
int main(){
    string sa2[10];
    int ia2[10];
}
```

    sa: 10个空字符串
    ia: 10个0
    sa2: 10个空字符串
    ia2: 10个未定义的值
    
[练习3.29](#)

>相比于vector来说，数组有哪些缺点，请列举一些。

    大小不可变
    不支持拷贝和赋值

[练习3.30](#)

>指出下面代码中的索引错误。

```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
    ia[ix] = ix;
```

    数组的索引从0开始，不是从1开始
    
[练习3.31](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_31.cpp)

>编写一个程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。

```cpp
int main()
{
    int arr[10];
    for(int i=0; i<10; i++)
    {
	arr[i]=i;
    }
    return 0;
}
```

[练习3.32](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_32.cpp)

>将上一题刚刚创建的数组拷贝给另一个数组。利用vector重写程序，实现类似的功能。

```cpp
#include<vector>
using namespace std;
int main()
{
    int arr[10];
    for(int i=0; i<10; i++)
    {
	arr[i]=i;
    }
	
    //数组拷贝
    int arr2[10];
    for(int i=0; i<10; i++)
    {
	arr2[i]=arr[i];
    }
	
	
    vector<int> ivec(10);
    for(int i=0; i<10; i++)
    {
	ivec[i] = i;
    }
    //vector拷贝
    vector<int> ivec2 = ivec;
    
    return 0;
}
```

[练习3.33](#)

>对于104页的程序来说，如果不初始化scores将会发生什么？

    如果不初始化scores，scores中元素的值是未定义的，++scores\[grade/10]会得到意想不到的结果
    
[练习3.34](#)

>假定p1和p2指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？

```cpp
p1 += p2 - p1;
```

    此句的结果类似p1 = p1，只要p2和p1都合法，此句就合法

[练习3.35](#)

>编写一段程序，利用指针将数组中的元素置为0。
