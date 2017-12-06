[练习3.1](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_1.cpp)

>使用恰当的using声明重做[1.4.1节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/README.md)（第11页）和[2.6.2节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/README.md)（第67页）的练习。

    以1.4.1节练习为例：
```
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

```
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

```
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

```
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

```
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

```
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

```
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

```
string s;
cout << s[0] <<endl;
```

    不合法，s默认初始化是空字符串，长度为0，不能访问第一个字符s[0]
    
[练习3.10](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_10.cpp)

>编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。

```
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

```
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

```
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

```
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
