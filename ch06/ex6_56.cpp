#include<iostream>
#include<vector>
using namespace std;

int add(int i1, int i2)
{
	return i1 + i2;
}
int subtract(int i1, int i2)
{
	return i1 - i2;
}
int product(int i1, int i2)
{
	return i1 * i2;
}
int divide(int i1, int i2)
{
	return i1 / i2;
}

int main()
{
	vector<decltype(add) *> vec;
	vec.push_back(add);
	vec.push_back(subtract);
	vec.push_back(product);
	vec.push_back(divide);
	
	int i1 = 10, i2 = 2;
	
	for(auto elem:vec)
	{
		cout<<elem(i1,i2)<<endl;
	}
}