[练习1.1](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_1.cpp)

>查阅你使用的编译器的文档，确定它所使用的文件命名约定。编译并运行第2页的main程序。

```cpp
int main()
{
    return 0;
}
```

[练习1.2](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_2.cpp)

>改写程序，让它返回-1。返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。

```cpp
int main()
{
    return -1;
}
```

[练习1.3](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_3.cpp)

>编写程序，在标准输出上打印Hello, World。

```cpp
#include<iostream>
int main()
{
    std::cout<<"Hello, World"<<std::endl;
    return 0;
}
```

[练习1.4](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_4.cpp)

>我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符\*，来打印两个数的积。

```cpp
#include<iostream>
int main()
{
    int v1,v2;
    std::cin>>v1>>v2;
    std::cout<<"The product of "<<v1<<" and "<<v2<<" is "<<v1*v2<<std::endl;
    return 0;
}
```

[练习1.5](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_5.cpp)

>我们将所有输出操作放在一条很长的语句中。重写程序，将每个运算对象的打印操作放在一条独立的语句中。

```cpp
#include<iostream>
int main()
{
    int v1,v2;
    std::cin>>v1>>v2;
    std::cout<<"The product of ";
    std::cout<<v1;
    std::cout<<" and ";
    std::cout<<v2;
    std::cout<<" is ";
    std::cout<<v1*v2;
    std::cout<<std::endl;
    return 0;
}
```

[练习1.6](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_6.cpp)

>解释下面程序片段是否合法。  
```cpp
std::cout << "The sum of " << v1;  
          << " and " << v2;  
          << " is " << v1+v2 << std::endl;  
```
>如果程序是合法的，它输出什么？如果程序不合法，原因何在？应该如何修正？

	不合法，第二行和第三行的<<运算符无左值，修正如下：

```cpp
#include<iostream>
int main()
{
    int v1, v2;
    std::cin>>v1>>v2;
    std::cout<<"The sum of "<<v1
             <<" and "<<v2
	     <<" is "<<v1+v2<<std::endl;
    return 0;
}
```

[练习1.7](#)

>编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。

	略

[练习1.8](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_8.cpp)

>指出下列哪些输出语句是合法的（如果有的话）：   
```
std::cout << "/\*";  
std::cout << "\*/";  
std::cout << /\* "\*/" \*/;  
std::cout << /\* "\*/" /\* "/\*" \*/;  
```
>预编译这些语句会产生什么样的结果，实际编译这些语句来验证你的答案（编写一个小程序，每次将上述一条语句作为其主体），改正每个编译错误。

	前两条合法，后两条相当于只有一个引号，所以缺少配对，改正如下：
```cpp
#include<iostream>
int main()
{
    std::cout<<"/*";
    std::cout<<"*/";
    std::cout<<"*/";
    std::cout<<"*/\"/*\"/*";
    return 0;
}
```

[练习1.9](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_9.cpp)

>编写程序，使用while循环将50到100的整数相加。

```cpp
#include<iostream>
int main()
{
    int sum = 0;
    int i = 50;
    while(i<=100)
    {
        sum+=i;
	i++;
    }
    std::cout<<"The sum of numbers from 50 to 100 is "<<sum<<std::endl;
    return 0;
}
```

[练习1.10](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_10.cpp)

>除了++运算符将运算对象的值增加1外，还有一个递减运算符（--）实现将值减少1,。编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。

```cpp
#include<iostream>
int main()
{
    std::cout<<"Numbers from ten down to zero are:"<<std::endl;
    int i = 10;
    while(i>=0)
    {
        std::cout<<i<<std::endl;
	i--;
    }
    return 0;
}
```

[练习1.11](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_11.cpp)

>编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。

```cpp
#include<iostream>
int main()
{
    std::cout<<"Please input two integers:"<<std::endl;
    int val1, val2;
    std::cin>>val1>>val2;
    if(val1<val2)
    {
        int swap = val1;
	val1=val2;
	val2=swap;
    }
    std::cout<<"Numbers in the range of "<<val1<<" and "<<val2<<" are:"<<std::endl;
    while(val1>=val2)
    {
        std::cout<<val1<<std::endl;
	val1--;
    }
    return 0;
}
```

[练习1.12](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_12.cpp)

>下面的for循环完成了什么功能？sum的终值是多少？  
```cpp
int sum = 0;  
for (int i = -100; i<=100; ++i)  
	sum += i;
```
	
	计算-100到100之间所有整数的和，sum的终值是0。

[练习1.13](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_13.cpp)

>使用for循环重做1.4.1节中的所有练习（第11页）。

```cpp
#include<iostream>
int main()
{
    //ex1_9
    int sum = 0;
    for(int i=50;i<=100;++i)
    {
        sum+=i;
    }
    std::cout<<"The sum of numbers from 50 to 100 is "<<sum<<std::endl;
	
    //ex1_10
    std::cout<<"Numbers from ten down to zero are:"<<std::endl;
    for(int i=10;i>=0;--i)
    {
        std::cout<<i<<std::endl;
    }
	
    //ex1_11
    std::cout<<"Please input two integers:"<<std::endl;
    int val1, val2;
    std::cin>>val1>>val2;
    if(val1<val2)
    {
        int swap = val1;
	val1=val2;
	val2=swap;
    }
    std::cout<<"Numbers in the range of "<<val1<<" and "<<val2<<" are:"<<std::endl;
    for(int i=val1;i>=val2;--i)
    {
        std::cout<<i<<std::endl;
    }
    return 0;
}
```

[练习1.14](#)

>对比for循环和while循环，两种形式的优缺点各是什么？

	略

[练习1.15](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_15.cpp)

>编写程序，包含第14页“再探编译”中讨论的常见错误。熟悉编译器生成的错误信息。

	略

[练习1.16](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_16.cpp)

>编写程序，从cin读取一组数，输出其和。

```cpp
#include<iostream>
int main()
{
    std::cout<<"Input integers to continue, non-integers to exit:"<<std::endl;
    int sum = 0;
    int val;
    while(std::cin>>val)
    {
        sum+=val;
    }
    std::cout<<"Sum of integers input is "<<sum<<std::endl;
    return 0;
}
```

[练习1.17](#)

>如果输入的所有值都是相等的，本节的程序会输出什么？如果没有重复值，输出又会是怎样的？

	如果输入的所有值都是相等的，本节程序会输出这个值和输入次数；如果没有重复值，输出是所有值和他们的输入次数，即1。

[练习1.18](#)

>编译并运行本节的程序，给它输入全部相等的值。再次运行程序，输入没有重复的值。

	略

[练习1.19](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_19.cpp)

>修改你为1.4.1节[练习1.11](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_11.cpp)（第11页）所编写的程序（打印一个范围内的数），使其能处理用户输入的第一个数比第二个数小的情况。

	当输入的第一个数比第二个数小时，练习1.11将交换这两个数，练习1.19将提示用户输入错误：

```cpp
#include<iostream>
int main()
{
    std::cout<<"Please input two integers:"<<std::endl;
    int val1, val2;
    std::cin>>val1>>val2;
    if(val1<val2)
    {
        std::cout<<"Wrong input!"<<std::endl;
    }
    else
    {
        std::cout<<"Numbers in the range of "<<val1<<" and "<<val2<<" are:"<<std::endl;
	while(val1>=val2)
	{
	    std::cout<<val1<<std::endl;
	    val1--;
	}
    }
    return 0;
}
```

[练习1.20](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_20.cpp)

>在网站[http://www.informit.com/title/0321714113](http://www.informit.com/title/0321714113) 上，第1章的代码目录中包含了头文件[Sales_item.h](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/Sales_item.h)。将它拷贝到你自己的动作目录中。用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。

```cpp
#include<iostream>
#include<vector>
#include "Sales_item.h"
int main()
{
    std::vector<Sales_item> items;
    Sales_item item;
    while(std::cin>>item)
    {
        items.push_back(item);
    }
    for(std::vector<Sales_item>::size_type i = 0;i<items.size();i++)
    {
        std::cout<<items[i]<<std::endl;
    }
    return 0;
}
```

[练习1.21](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_21.cpp)

>编写程序，读取两个ISBN相同的[Sales_item](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/Sales_item.h)对象，输出它们的和。

```cpp
#include<iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    std::cin>>item1>>item2;
    if(item1.isbn()!=item2.isbn())
    {
        std::cout<<"Wrong input!"<<std::endl;
    }
    else
    {
        std::cout<<item1+item2;
    }
    return 0;
}
```

[练习1.22](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_22.cpp)

>编写程序，读取多个具有相同ISBN的销售记录，输出所有记录的和。

```cpp
#include<iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    std::cin>>item1;
    while(std::cin>>item2)
    {
        if(item1.isbn()!=item2.isbn())
	{
	    std::cout<<"Wrong input!"<<std::endl;
	    break;
	}
	else
	{
	    item1=item1+item2;
	}
    }
    std::cout<<item1;
    return 0;
}
```

[练习1.23](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_23.cpp)

>编写程序，读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录。

```cpp
#include<iostream>
#include<vector>
#include "Sales_item.h"
int main()
{
    std::vector<std::string> isbns;
    std::vector<int> nums;
    Sales_item item;
    while(std::cin>>item)
    {
        bool exist = false;
	for(std::vector<std::string>::size_type i = 0;i<isbns.size();i++)
	{
	    if(isbns[i]==item.isbn())
	    {
	        nums[i]++;
		exist=true;
		break;
	    }
	}
	if(!exist)
	{
	    isbns.push_back(item.isbn());
	    nums.push_back(1);
	}
    }
    std::cout<<"All ISBNS with their transactions counts are:"<<std::endl;
    for(std::vector<std::string>::size_type i = 0;i<isbns.size();i++)
    {
        std::cout<<"ISBN: "<<isbns[i]<<", counts: "<<nums[i]<<std::endl;
    }
    return 0;
}
```

[练习1.24](#)

>输入表示多个ISBN的多条销售记录来测试上一个程序，每个ISBN的记录应该聚在一起。

	略

[练习1.25](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_25.cpp)

>借助网站上的[Sales_item.h](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/Sales_item.h)头文件，编译并运行本节给出的书店程序。

```cpp
#include<iostream>
#include "Sales_item.h"
int main()
{
    Sales_item total; //保存下一条交易记录的变量
    //读入第一条交易记录，并确保有数据可以处理
    if(std::cin>>total){
	Sales_item trans; //保存和的变量
	//读入并处理剩余交易记录
	while(std::cin >> trans){
	    //如果我们仍在处理相同的书
	    if(total.isbn() == trans.isbn())
	        total += trans; //更新总销售额
	    else{
		//打印前一本书的结果
		std::cout << total << std::endl;
		total = trans; //total现在表示下一本书的销售额
	        }
	}
	std::cout << total << std::endl; //打印最后一本书的结果
    }else{
	//没有输入！警告读者
	std::cerr << "No data?!" << std::endl;
	return -1; //表示失败
    }
    return 0;
}
```
