#include<iostream>
using namespace std;

void f()
{
	cout<<"version I"<<endl;
}

void f(int i)
{
	cout<<"version II"<<endl;
}

void f(int i1, int i2)
{
	cout<<"version III"<<endl;
}

void f(double d1, double d2 = 3.14)
{
	cout<<"version IV"<<endl;
}

int main()
{
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
}