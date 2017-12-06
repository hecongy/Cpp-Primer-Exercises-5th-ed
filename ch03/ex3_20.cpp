#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int i;
	vector<int> ivec;
	cout<<"Please input integer sequence:"<<endl;
	while(cin>>i)
	{
		ivec.push_back(i);
	}
	
	decltype(ivec.size()) b = 0;
	auto e = ivec.size()-1;
	
	cout<<"Sum of adjacent members are:"<<endl;

	while(b+1<=e)
	{
		cout<<ivec[b]+ivec[b+1]<<endl;
		b=b+2;
	}
	if(b==e)
		cout<<ivec[e]<<endl;
	
	b=0;
	cout<<"Sum of symmetrical members are:"<<endl;
	while(b<e)
	{
		cout<<ivec[b]+ivec[e]<<endl;
		b++;
		e--;
	}
	if(b==e)
		cout<<ivec[e]<<endl;
	
	return 0;
}