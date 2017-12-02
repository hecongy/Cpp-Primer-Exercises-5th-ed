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