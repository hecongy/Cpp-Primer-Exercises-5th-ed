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
