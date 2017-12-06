#include<iostream>
#include<string>
using namespace std;
int main()
{
	cout<<"Please input a string:"<<endl;
	string s;
	getline(cin,s);
	for(auto &c:s)
	{
		c='X';
	}
	cout<<"The result is: "<<s<<endl;
	return 0;
}