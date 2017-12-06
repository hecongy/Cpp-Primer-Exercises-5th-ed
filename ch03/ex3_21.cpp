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
	for(auto it=v1.begin();it<v1.end();it++)
		cout<<*it<<endl;
	
	cout<<"v2 contains "<<v2.size()<<" elements. They are:"<<endl;
	for(auto it=v2.begin();it<v2.end();it++)
		cout<<*it<<endl;
	
	cout<<"v3 contains "<<v3.size()<<" elements. They are:"<<endl;
	for(auto it=v3.begin();it<v3.end();it++)
		cout<<*it<<endl;
	
	cout<<"v4 contains "<<v4.size()<<" elements. They are:"<<endl;
	for(auto it=v4.begin();it<v4.end();it++)
		cout<<*it<<endl;
	
	cout<<"v5 contains "<<v5.size()<<" elements. They are:"<<endl;
	for(auto it=v5.begin();it<v5.end();it++)
		cout<<*it<<endl;
	
	cout<<"v6 contains "<<v6.size()<<" elements. They are:"<<endl;
	for(auto it=v6.begin();it<v6.end();it++)
		cout<<*it<<endl;
	
	cout<<"v7 contains "<<v7.size()<<" elements. They are:"<<endl;
	for(auto it=v7.begin();it<v7.end();it++)
		cout<<*it<<endl;
	
	return 0;
}