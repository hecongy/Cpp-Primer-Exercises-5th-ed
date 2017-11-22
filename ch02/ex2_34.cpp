/*
* Write a program containing the variables and assignments from
* the previous exercise. Print the variables before and after the
* assignments to check whether your predictions in the previous 
* exercise were correct. If not, study the examples until you can
* convince yourself you know what led you to the wrong conclusion.
*/
#include<iostream>
int main()
{
	int i=0, &r=i;
	auto a = r;
	const int ci=i,&cr=ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto &g = ci;
	
	std::cout<<"a="<<a<<", b="<<b<<", c="<<c
	<<", d="<<d<<", e="<<e<<", g="<<g<<std::endl;
	
	a=42;
	b=42;
	//c=42;
	//d=42;
	//e=42;
	//g=42;
	
	std::cout<<"a="<<a<<", b="<<b<<", c="<<c
	<<", d="<<d<<", e="<<e<<", g="<<g<<std::endl;
	return 0;
}