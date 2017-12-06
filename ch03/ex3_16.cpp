#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,42);
	vector<int> v4{10};
	vector<int> v5{10,42};
	vector<string> v6{10};
	vector<string> v7{10,"hi"};
	
	cout<<"v1 contains "<<v1.size()<<" elements. They are:"<<endl;
	for(auto e:v1)
	{
		cout<<e<<endl;
	}
	
	cout<<"v2 contains "<<v2.size()<<" elements. They are:"<<endl;
	for(auto e:v2)
	{
		cout<<e<<endl;
	}
	
	cout<<"v3 contains "<<v3.size()<<" elements. They are:"<<endl;
	for(auto e:v3)
	{
		cout<<e<<endl;
	}
	
	cout<<"v4 contains "<<v4.size()<<" elements. They are:"<<endl;
	for(auto e:v4)
	{
		cout<<e<<endl;
	}
	
	cout<<"v5 contains "<<v5.size()<<" elements. They are:"<<endl;
	for(auto e:v5)
	{
		cout<<e<<endl;
	}
	
	cout<<"v6 contains "<<v6.size()<<" elements. They are:"<<endl;
	for(auto e:v6)
	{
		cout<<e<<endl;
	}
	
	cout<<"v7 contains "<<v7.size()<<" elements. They are:"<<endl;
	for(auto e:v7)
	{
		cout<<e<<endl;
	}
	
	return 0;
}