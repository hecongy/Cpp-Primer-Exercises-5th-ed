[练习5.1](#)

>什么是空语句？什么时候会用到空语句？

    空语句是指含有一个单独的分号的语句，当语法上需要一条语句但逻辑上不需要时使用

[练习5.2](#)

>什么时块？什么时候会用到块？

    块是指用花括号括起来的（可能为空的）语句和声明的序列，当语法上需要一条语句但逻辑上需要多条语句时使用

[练习5.3](#)

>使用逗号运算符（参见4.10节，第140页）重写1.4.1节（第10页）的while循环，使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。

    可读性降低

```cpp
//原程序
while (val <= 10) {
    sum += val;
    ++val;
}

//改写
while (val <= 10)
    sum += val, ++val;
```

[练习5.4](#)

>说明下列例子的含义，如果存在问题，试着修改它。  
(a) while (string::iterator iter != s.end()) { /* ... \*/ }  
(b) while (bool status = find(word)) { /* ... \*/ }  
        if (!status) { /* ... \*/}
        
    (a) iter未初始化，修改：
        string::iterator iter = s.begin();
        while (iter != s.end()) { /* ... */ }  
    (b) status的作用域在while中，所以if中不能使用status，修改：
        bool status;
        while (status = find(word)) { /* ... */ }  
            if (!status) { /* ... */}
            
[练习5.5](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch05/ex5_5.cpp)

>写一段自己的程序，使用if else语句实现把数字成绩转换成字母成绩的要求。

    程序中使用后缀vector tails，省略了判断余数的if
```cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int grade;
    cin >> grade;
    while(grade<0 || grade>100)
    {
	    cout<<"Wrong input!"<<endl;
        cout<<"Please input again: ";
        cin>>grade;
    }
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    const vector<string> tails = {"-","-","-","","","","","","+","+"};
    string lettergrade;
    if(grade<60)
	    lettergrade = scores[0];
    else
    {
	    lettergrade = scores[(grade-50)/10];
	    if(grade!=100)
        {
		    lettergrade+=tails[grade%10];
	    }
    }
	
    cout<<"Grade is: "<<grade<<", "<<lettergrade<<endl;
    return 0;
}
```

[练习5.6](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch05/ex5_6.cpp)

>改写上一题的程序，使用条件运算符（参见4.7节，第134页）代替if else语句。

```cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int grade;
    cin >> grade;
    while(grade<0 || grade>100)
    {
	    cout<<"Wrong input!"<<endl;
        cout<<"Please input again: ";
        cin>>grade;
    }
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    const vector<string> tails = {"-","-","-","","","","","","+","+"};
    string lettergrade;
    
    lettergrade = grade<60?scores[0]:scores[(grade-50)/10];
    lettergrade += grade==100?"":tails[grade%10];
	
    cout<<"Grade is: "<<grade<<", "<<lettergrade<<endl;
    return 0;
}
```

[练习5.7](#)

>改正下列代码段中的错误。

```diff
//(a)
if (ival1 != ival2)
    ival1 = ival2; //缺少分号
else ival1 = ival2 = 0;

//(b)
if (ival < minval) 
+ { //增加块作用域，否则occurs = 1落在作用域外
    minval = ival;
    occurs = 1;
+ }
```
