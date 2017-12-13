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
    int count = 0;
    char c;
    while(cin>>c)
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

[练习5.11](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch05/ex5_11.cpp)

>修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。

    特殊字符需要使用getchar()获得

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{	
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt = 0, tCnt = 0, fCnt = 0;
    char ch;
    while(ch = getchar())
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
	    case 32:
		++sCnt;
		break;
	    case '\t':
		++tCnt;
		break;
	    case '\n':
		++fCnt;
		break;
	}
    }
	
    cout<<"Number of vowel a: \t"<<aCnt<<'\n'
	<<"Number of vowel e: \t"<<eCnt<<'\n'
	<<"Number of vowel i: \t"<<iCnt<<'\n'
	<<"Number of vowel o: \t"<<oCnt<<'\n'
	<<"Number of vowel u: \t"<<uCnt<<'\n'
	<<"Number of space: \t"<<sCnt<<'\n'
	<<"Number of tab: \t"<<tCnt<<'\n'
	<<"Number of newline: \t"<<fCnt<<'\n';
    return 0;
}
```

[练习5.12](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch05/ex5_12.cpp)

>修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量：ff、fl和fi。

    首先过滤首字母是f的序列，不以f开头则跳过，然后使用switch检查第二个字符，使用flag标记输入的字母是首字母还是第二个字母
```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{	
    unsigned fCnt = 0, lCnt = 0, iCnt = 0;
    bool flag = true; //flag标识是否是序列中的第一个字母
    char ch;
    while(cin >> ch)
    {		
	if(ch!='f' && flag) //不以f开头的第一个字母跳过
	    continue;
	if(ch=='f' && flag) //以f开头的第一个字母将flag置反并跳过
	{
	    flag = false;
	    continue;
	}		
	switch(ch){
	    case 'f':
		++fCnt;
		break;
	    case 'l':
		++lCnt;
		break;
	    case 'i':
		++iCnt;
		break;
	}
	flag=true; //序列处理完毕，flag置位
    }
	
    cout<<"Number of ff: \t"<<fCnt<<'\n'
	<<"Number of fl: \t"<<lCnt<<'\n'
	<<"Number of fi: \t"<<iCnt<<'\n';
    return 0;
}
```

[练习5.13](#)

>下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。

```diff
//(a)
+ 没有break;
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch(ch) {
+   case 'a':
+       aCnt++;
+	break;
-   case 'a': aCnt++;
+   case 'e':
+       eCnt++;
+	break;
-   case 'e': eCnt++;
+   default:
+       iouCnt++;
+	break;
-   default: iouCnt++;
}

//(b)
+ ix的作用域问题
unsigned index = some_value();
+ int ix;
switch (index) {
    case 1:
+       ix = get_value();
-       int ix = get_value();
	ivec[ ix ] = index;
	break;
    default:
        ix = ivec.size() - 1;
	ivec[ ix ] = index;
}

//(c)
+ case标签必须是整型常量表达式（语法错误）
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit){
+   case (1,3,5,7,9):    
-   case 1,3,5,7,9:
        oddCnt++;
	break;
+   case (2,4,6,8,10):
-   case 2,4,6,8,10:
        evenCnt+=;
	break;
}

//(d)
+ case标签必须是整型常量表达式
+ constexpr unsigned ival = 512, jval = 1024, kval = 4096;
- unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt){
    case ival:
        bufsize = ival * sizeof(int);
	break;
    case jval:
        bufsize = jval * sizeof(int);
	break;
    case kval:
        bufsize = kval * sizeof(int);
	break;
}
```

[练习5.14](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch05/ex5_14.cpp)

>编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词。所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数。如果不存在，输出一条信息说明任何单词都没有连续出现过。例如，如果输入是  
how now now now brown cow cow  
那么输出应表明单词now连续出现了3次。  

    定义变量记录当前连续出现次数最多单词maxWord（使用vector以防出现次数重复）及其出现的次数maxNum
    定义变量记录当前记录的单词curWord及其已经出现的次数curNum
    当出现与curWord不同的单词时结束curNum递增并与maxNum比较，如果curNum>maxNum时更新maxWord和maxNum。

```cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{	
    vector<string> maxWords;
    string curWord;	
    int maxNum=1,curNum=1;
    cout<<"Please input words:"<<endl;
	
    //获得第一个输入的单词
    cin>>curWord;
    maxWords.push_back(curWord);
    string inputWord;
    while(cin>>inputWord)
    {
	if(inputWord == curWord) //重复输入
	{
	    curNum++;
	}
	else //不重复输入
	{
	    if(curNum>maxNum) //当前最大
	    {
		maxWords={curWord};
	        maxNum=curNum;
	    }
	    else if(curNum==maxNum) //当前最大之一
	    {
		maxWords.push_back(curWord);
	    }	
	    curNum = 1;
	}
	curWord = inputWord; //当前输入
    }
	
    if(maxNum<=1)
	cout<<"No word repeats.";
    else
    {
	cout<<"Words: ";
	for(auto e:maxWords)
	{
	    cout<<e<<" ";
	}
	cout<<"repeat "<<maxNum<<" times."<<endl;
    }
    return 0;
}
```

[练习5.15](#)

>说明下列循环的含义并改正其中的错误。

```diff
//(a)
+ ix作用域问题
+ int ix;
+ for (ix = 0; ix !=sz; ++ix) { /* ... */ }
- for (int ix = 0; ix !=sz; ++ix) { /* ... */ }
if (ix != sz)
    // ...

//(b)
+ for不完整
int ix;
+ for(ix = 0; ix != sz; ++ix) { /* ... */ }
- for(ix != sz; ++ix) { /* ... */ }

//(c)
+ for不正确
+ for (int ix = 0; ix != sz; ++ix, ++sz) { /* ... */ }
- for (int ix = 0; ix != sz; ++ix; ++sz) { /* ... */ }
```

[练习5.16](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch05/ex5_16.cpp)

>while循环特别适用于那种条件保持不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for循环则更像是在按步骤迭代，它的索引值在某个范围内依次变。根据每种循环的习惯用法各自编写一段程序，然后分别用另一种循环改写。如果只能使用一种循环，你倾向于使用哪种呢？为什么？

```cpp
int main()
{
    int arr[] = {1,2,3,5,6,7,8,9};
	
    //for
    for(int i=0;i<9;i++)
    {
	arr[i] = arr[i]+1;
    }
	
    //while
    int i = 0;
    while(i<9)
    {
	arr[i] = arr[i]+1;
    }
    return 0;
}
```

    都可以，while可以实现的for也可以实现，反之亦然

[练习5.17](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch05/ex5_17.cpp)

>假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。例如，如果两个vector对象的元素分别是0、1、1、2和0、1、1、2、3、5、8，则程序的返回结果应该为0。

```cpp
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<int> vec1 = {0,1,1,2,3,5,8};
    vector<int> vec2 = {0,1,1,2};
	
    auto b1 = vec1.begin();
    auto e1 = vec1.end();
    auto b2 = vec2.begin();
    auto e2 = vec2.end();

    bool flag = true;
    for(;b1<e1 && b2<e2;b1++,b2++)
    {
	if(*b1 != *b2)
	{
	    flag = false;
	}
    }
    if(!flag)
    {
	cout<<"No."<<endl;
    }
    else
    {
	if(b1==e1 && b2==e2)
	    cout<<"vec1 equals vec2."<<endl;
	else if(b1==e1)
	    cout<<"vec1 is prefix of vec2."<<endl;
	else
	    cout<<"vec2 is prefix of vec1."<<endl;
    }
    return 0;
}
```
