/*
* Write a program that reads several transactions and counts
* how many transactions occur for each ISBN.
*/
#include<iostream>
#include<vector>
#include "Sales_item.h"
int main()
{
	std::vector<std::string> isbns;
	std::vector<int> nums;
	Sales_item item;
	while(std::cin>>item)
	{
		bool exist = false;
		for(std::vector<std::string>::size_type i = 0;i<isbns.size();i++)
		{
			if(isbns[i]==item.isbn())
			{
				nums[i]++;
				exist=true;
				break;
			}
		}
		if(!exist)
		{
			isbns.push_back(item.isbn());
			nums.push_back(1);
		}
	}
	std::cout<<"All ISBNS with their transactions counts are:"<<std::endl;
	for(std::vector<std::string>::size_type i = 0;i<isbns.size();i++)
	{
		std::cout<<"ISBN: "<<isbns[i]<<", counts: "<<nums[i]<<std::endl;
	}
	return 0;
}