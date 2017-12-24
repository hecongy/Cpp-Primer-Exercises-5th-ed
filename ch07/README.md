[练习7.1](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_1.cpp)

>使用[2.6.1节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/README.md)练习定义的[Sales_data类](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_40.cpp)为1.6节（第21页）的交易处理程序编写一个新版本。

```cpp
#include<iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
    Sales_data total; //保存下一条交易记录的变量
    //读入第一条交易记录，并确保有数据可以处理
    if(total.input(cin)){
	Sales_data trans; //保存和的变量
	//读入并处理剩余交易记录
	while(trans.input(cin)){
	    //如果我们仍在处理相同的书
	    if(total.isbn() == trans.isbn())
		total.add(trans); //更新总销售额
	    else{
		//打印前一本书的结果
		total.print(cout);
		total = trans; //total现在表示下一本书的销售额
	    }
	}
	total.print(cout); //打印最后一本书的结果
    }else{
	//没有输入！警告读者
	std::cerr << "No data?!" << std::endl;
	return -1; //表示失败
    }
    return 0;
}
```

[练习7.2](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Sales_data.h)

>曾在[2.6.2节]((https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/README.md))的练习（第67页）中编写了一个Sales_data类，请向这个类添加combine和isbn成员。

```cpp
#include<iostream>
#include<string>
struct Sales_data {
	
    private:
	std::string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	double revenue = 0.0;
	
    public:
	bool input(std::istream &in)
	{
	    in >> bookNo >>units_sold >>price;
	    if(!in) return false;
	    revenue = units_sold * price;
	    return true;
	}

	void add(Sales_data data)
	{
	    units_sold += data.units_sold;
	    revenue += data.revenue;
	}
		
	Sales_data& combine(const Sales_data &data)
	{
	    units_sold += data.units_sold;
	    revenue += data.revenue;
	    return *this;
	}

	void output(std::ostream &out)
	{
	    out << bookNo << " " << units_sold << " " << revenue << " " << price << std::endl;
	}

	void print(std::ostream &out)
	{
	    out << "Revenue of " << bookNo << " is " << revenue << std::endl;
	}
		
	std::string isbn() const
	{
	    return bookNo;
	}
};
```

[练习7.3](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_3.cpp)

>修改[7.1.1节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_1.cpp)（第229页）的交易处理程序，令其使用这些成员。

```cpp
#include<iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
    Sales_data total; //保存下一条交易记录的变量
    //读入第一条交易记录，并确保有数据可以处理
    if(total.input(cin)){
	Sales_data trans; //保存和的变量
	//读入并处理剩余交易记录
	while(trans.input(cin)){
	    //如果我们仍在处理相同的书
	    if(total.isbn() == trans.isbn())
		total = total.combine(trans); //更新总销售额
	    else{
		//打印前一本书的结果
		total.print(cout);
		total = trans; //total现在表示下一本书的销售额
	    }
	}
	total.print(cout); //打印最后一本书的结果
    }else{
	//没有输入！警告读者
	std::cerr << "No data?!" << std::endl;
	return -1; //表示失败
    }
    return 0;
}
```

[练习7.4](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Person.h)

>编写一个名为Person的类，使其表示人员的姓名和住址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。

    见下

[练习7.5](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Person.h)

>在你的Person类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是const的呢？解释原因。

```cpp
#include<string>
using namespace std;

struct Person{

    private:
        string name;
	string address;
	
    public:
	string get_name() const
	{
	    return name;
	}
	string get_address() const
	{
	    return address;
	}
};
```

    读取姓名和地址的成员函数不需要修改对象的数据成员，因此应该是const的

[练习7.6](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Sales_data_ex_7_6.h)

>对于函数add、read和print，定义你自己的版本。

```cpp
#include<iostream>
#include<string>
using namespace std;
struct Sales_data {
	
    public:
	string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	double revenue = 0.0;
		
	Sales_data& combine(const Sales_data &data)
	{
	    units_sold += data.units_sold;
	    revenue += data.revenue;
	    return *this;
	}
		
	string isbn() const
	{
	    return bookNo;
	}
		
	double avg_price() const
	{
	    if(units_sold)
		return revenue/units_sold;
	    else
		return 0;
	}
};

Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
    Sales_data sum = item1;
    return sum.combine(item2);
}

istream &read(istream &in, Sales_data &item)
{
    double price = 0.0;
    in >> item.bookNo >>item.units_sold >>item.price;
    item.revenue = item.units_sold * item.price;
    return in;
}

ostream &print(ostream &out, Sales_data &item)
{
    out<<"ISBN: "<<item.isbn()<<" sold out "<<item.units_sold<<" pieces, revenue is: "<<item.revenue<<", average price is: "<<item.avg_price();
    return out;
}
```

[练习7.7](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_7.cpp)

>使用这些新函数重写[7.1.2节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_3.cpp)（第233页）练习中的交易处理程序。

```cpp
#include<iostream>
#include "Sales_data_ex_7_6.h"
using namespace std;
int main()
{
    Sales_data total; //保存下一条交易记录的变量
    //读入第一条交易记录，并确保有数据可以处理
    if(read(cin,total)){
	Sales_data trans; //保存和的变量
	//读入并处理剩余交易记录
	while(read(cin,trans)){
	    //如果我们仍在处理相同的书
	    if(total.isbn() == trans.isbn())
		total = total.combine(trans); //更新总销售额
	    else{
		//打印前一本书的结果
		print(cout,total);
		total = trans; //total现在表示下一本书的销售额
	    }
	}
	print(cout,total); //打印最后一本书的结果
    }else{
	//没有输入！警告读者
	std::cerr << "No data?!" << std::endl;
	return -1; //表示失败
    }
    return 0;
}
```

[练习7.8](#)

>为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义成常量引用？

    read函数要改变其参数的数据成员的值（输入），所以是普通引用
    print函数只需读取参数的数据成员而不需要改变它们，所以是常量引用

[练习7.9](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_9.cpp)

>对于[7.1.2节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_4.cpp)（第233页）练习中的代码，添加读取和打印Person对象的操作。

```cpp
#include<iostream>
#include<string>
using namespace std;

struct Person{
    public:
        string name;
	string address;

	string get_name() const
	{
	    return name;
	}
	string get_address() const
	{
	    return address;
	}
};

istream &read(istream &in, Person &person)
{
    in>>person.name>>person.address;
    return in;
}

ostream &print(ostream &out, const Person &person)
{
    out<<person.name<<" "<<person.address;
    return out;
}
```

[练习7.10](#)

>在下面这条if语句中，条件部分的作用是什么？

```cpp
if (read(read(cin, data1), data2))
```

    首先输入data1，再用返回的cin输入data2，相当于cin>>data1>>data2

[练习7.11](#)
