#include<iostream>
int main()
{
	int num1 = 5;
	int num2 = 6;
	int *p = &num1;
	std::cout<<"num1 change from "<<*p;
	*p = 7;
	std::cout<<" to "<<*p<<std::endl;
	
	std::cout<<"p pointers from "<<*p;
	p = &num2;
	std::cout<<" to "<<*p<<std::endl;
	return 0;
}