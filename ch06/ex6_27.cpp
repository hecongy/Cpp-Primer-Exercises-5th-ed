#include<iostream>
#include<initializer_list>
using namespace std;
int sum(initializer_list<int> il)
{
	int sum = 0;
	for(const auto elem : il)
	{
		sum += elem;
	}
	return sum;
}

int main()
{
	cout<<sum({1,2,3,4,5})<<endl;
	return 0;
}