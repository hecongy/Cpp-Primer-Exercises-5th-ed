/*
* In addition to the ++ operator that adds 1 to its operand,
* there is a decrement operator (--) that subtracts 1. Use the 
* decrement operator to write a while that prints the numbers 
* from ten down to zero.
*/
#include<iostream>
int main()
{
	std::cout<<"Numbers from ten down to zero are:"<<std::endl;
	int i = 10;
	while(i>=0)
	{
		std::cout<<i<<std::endl;
		i--;
	}
	return 0;
}