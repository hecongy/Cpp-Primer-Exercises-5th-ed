#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<int> vec1 = {0,1,1,2,3,5,8};
	vector<int> vec2 = {0,1,1,2};
	
	auto b1 = vec1.begin();
	auto e1 = vec1.end();
	auto b2 = vec2.begin();
	auto e2 = vec2.end();
	
	bool flag = true;
	for(;b1<e1 && b2<e2;b1++,b2++)
	{
		if(*b1 != *b2)
		{
			flag = false;
		}
	}
	if(!flag)
	{
		cout<<"No."<<endl;
	}
	else
	{
		if(b1==e1 && b2==e2)
			cout<<"vec1 equals vec2."<<endl;
		else if(b1==e1)
			cout<<"vec1 is prefix of vec2."<<endl;
		else
			cout<<"vec2 is prefix of vec1."<<endl;
	}
	return 0;
}