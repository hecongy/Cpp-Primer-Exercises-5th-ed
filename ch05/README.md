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
+   ival1 = ival2; //缺少分号
-   ival1 = ival2
else ival1 = ival2 = 0;

//(b)
if (ival < minval) 
+ { //增加块作用域，否则occurs = 1落在作用域外
    minval = ival;
    occurs = 1;
+ }

//(c)
+ int ival; //扩大ival的作用域，否则if(!ival)非法
+ if (ival = get_value())
- if (int ival = get_value())
    cout << "ival = " << ival << endl;
if (!ival)
    cout << "ival = 0\n";

//(d)
+ if (ival == 0) //应该使误把赋值当作相等性判断
- if (ival = 0)
    ival = get_value();
```

[练习5.8](#)

>什么是“悬垂else”？C++语言是如何处理else子句的？

    if分支多于else分支时产生悬垂else，C++语言规定else与离它最近的尚未匹配的if匹配

[练习5.9](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch05/ex5_9.cpp)

>编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int count = 0;
	
    for(auto c:s)
    {
	if(c=='a')
	    count++;
	if(c=='e')
	    count++;
	if(c=='i')
	    count++;
	if(c=='o')
	    count++;
        if(c=='u')
	    count++;
	if(c=='A')
	    count++;
	if(c=='E')
	    count++;
	if(c=='I')
	    count++;
	if(c=='O')
	    count++;
        if(c=='U')
	    count++;
    }
	
    cout<<"The number of vowels is: "<<count<<endl;
    return 0;
}
```

[练习5.10](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch05/ex5_10.cpp)

>我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到'a'和'A'都应该递增aCnt的值，以此类推。

可以增加switch中的case，或者将大写字母（65~90）转换成小写字母（+32）
```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{	
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while(cin >> ch)
    {
	if(ch>=65 && ch<=90) //大写换小写
	    ch += 32;
	switch(ch){
	    case 'a':
                ++aCnt;
		break;
	    case 'e':
		++eCnt;
		break;
	    case 'i':
		++iCnt;
                break;
	   case 'o':
	        ++oCnt;
		break;
	    case 'u':
		++uCnt;
		break;
	}
    }
	
    cout<<"Number of vowel a: \t"<<aCnt<<'\n'
	<<"Number of vowel e: \t"<<eCnt<<'\n'
	<<"Number of vowel i: \t"<<iCnt<<'\n'
	<<"Number of vowel o: \t"<<oCnt<<'\n'
	<<"Number of vowel u: \t"<<uCnt<<'\n';
    return 0;
}
```
