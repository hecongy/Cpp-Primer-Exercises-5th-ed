/*
* What does the following for loop do? What is the final value of sum?
*/
#include<iostream>
int main()
{
	int sum=0;
	//add from -100 to 99, the result is -100
	for(int i=-100;i<100;++i)
	{
		sum+=i;
	}
	std::cout<<"The result is "<<sum<<std::endl;
}