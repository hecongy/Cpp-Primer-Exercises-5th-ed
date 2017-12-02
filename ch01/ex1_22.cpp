#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item1, item2;
	std::cin>>item1;
	while(std::cin>>item2)
	{
		if(item1.isbn()!=item2.isbn())
		{
			std::cout<<"Wrong input!"<<std::endl;
			break;
		}
		else
		{
			item1=item1+item2;
		}
	}
	std::cout<<item1;
	return 0;
}