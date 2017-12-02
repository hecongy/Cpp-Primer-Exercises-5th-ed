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