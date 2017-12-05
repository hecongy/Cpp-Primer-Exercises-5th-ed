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