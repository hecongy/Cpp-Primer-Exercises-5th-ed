#include<iostream>
int main()
{
	const int i=42;
	auto j=i;
	const auto &k=i;
	auto *p=&i;
	const auto j2=i,&k2=i;
	std::cout<<"type of j is: "<<typeid(j).name()<<std::endl;
	std::cout<<"type of k is: "<<typeid(k).name()<<std::endl;
	std::cout<<"type of p is: "<<typeid(p).name()<<std::endl;
	std::cout<<"type of j2 is: "<<typeid(j2).name()<<std::endl;
	std::cout<<"type of k2 is: "<<typeid(k2).name()<<std::endl;
	return 0;
}