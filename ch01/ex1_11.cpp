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