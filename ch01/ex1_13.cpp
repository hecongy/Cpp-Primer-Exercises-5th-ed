/*
* Rewrite the first two exercises from $1.4.1(p.13) using for loops.
* That is: sum the numbers from 50 to 100.
*/
#include<iostream>
int main()
{
	int sum = 0;
	for(int i=50;i<=100;++i)
	{
		sum+=i;
	}
	std::cout<<"The sum of numbers from 50 to 100 is "<<sum<<std::endl;
	return 0;
}