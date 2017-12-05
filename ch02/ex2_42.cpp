#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include "Sales_data.h"
int main()
{
	//ex1_20
	std::vector<Sales_data> items;
	Sales_data item;
	while (item.input(std::ref(std::cin)))
	{
		items.push_back(item);
	}
	for (std::vector<Sales_data>::size_type i = 0; i<items.size(); i++)
	{
		items[i].output(std::ref(std::cout));
	}
	
	//ex1_21
	Sales_data item1, item2;
	item1.input(std::ref(std::cin));
	item2.input(std::ref(std::cin));
	if(item1.isbn()!=item2.isbn())
	{
		std::cout<<"Wrong input!"<<std::endl;
	}
	else
	{
		item1.add(item2);
		item1.output(std::ref(std::cout));
	}
	
	//ex1_22
	item1.input(std::ref(std::cin));
	while(item2.input(std::ref(std::cin)))
	{
		if(item1.isbn()!=item2.isbn())
		{
			std::cout<<"Wrong input!"<<std::endl;
			break;
		}
		else
		{
			item1.add(item2);
		}
	}
	item1.output(std::ref(std::cout));
	
	//ex1_23 & ex1_24
	std::vector<std::string> isbns;
	std::vector<int> nums;
	while(item.input(std::ref(std::cin)))
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
	
	//ex1_25
	Sales_data total; //保存下一条交易记录的变 量
	//读入第一条交易记录，并确保有数据可以处理
	if(total.input(std::ref(std::cin))){
		Sales_data trans; //保存和的变量
		//读入并处理剩余交易记录
		while(trans.input(std::ref(std::cin))){
			//如果我们仍在处理相同的书
			if(total.isbn() == trans.isbn())
				total.add(trans); //更新总销售额
			else{
				//打印前一本书的结果
				total.output(std::ref(std::cout));
				total = trans; //total现在表示下一本书的销售额
			}
		}
		total.output(std::ref(std::cout)); //打印最后一本书的结果
	}else{
		//没有输入！警告读者
		std::cerr << "No data?!" << std::endl;
		return -1; //表示失败
	}
	
	return 0;
}