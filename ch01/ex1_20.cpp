/*
* Write a program that prompts the user for two integers.
* Print each number in the range specified by those two integers.
*/
#include<iostream>
#include<vector>
#include "Sales_item.h"
int main()
{
	std::vector<Sales_item> items;
	Sales_item item;
	while(std::cin>>item)
	{
		items.push_back(item);
	}
	for(std::vector<Sales_item>::size_type i = 0;i<items.size();i++)
	{
		std::cout<<items[i]<<std::endl;
	}
	return 0;
}