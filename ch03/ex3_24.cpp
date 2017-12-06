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
	
	auto b = ivec.begin();
	auto e = ivec.end()-1;
	
	cout<<"Sum of adjacent members are:"<<endl;

	while(b+1<=e)
	{
		cout<<*b + *(b+1)<<endl;
		b=b+2;
	}
	if(b==e)
		cout<<*e<<endl;
	
	b=ivec.begin();
	cout<<"Sum of symmetrical members are:"<<endl;
	while(b<e)
	{
		cout<<*b + *e<<endl;
		b++;
		e--;
	}
	if(b==e)
		cout<<*e<<endl;
	
	return 0;
}