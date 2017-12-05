[练习3.1](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch03/ex3_1.cpp)

>使用恰当的using声明重做1.4.1节（第11页）和2.6.2节（第67页）的练习。

    以1.4.1节练习为例：
```
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	ex1_9();
	ex1_10();
	ex1_11();
	return 0;
}

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
```
