#include<iostream>
#include<string>
using namespace std;

//while循环
void whileloop()
{
	cout<<"Please input a string:"<<endl;
	string s;
	getline(cin,s);
	
	decltype(s.size()) i = 0;
	while(i<s.size())
	{
		s[i] = 'X';
		i++;
	}
	cout<<"The result is: "<<s<<endl;
}

//传统for循环
void traditionalforloop()
{
	cout<<"Please input a string:"<<endl;
	string s;
	getline(cin,s);
	
	for(decltype(s.size()) i=0;i<s.size();i++)
	{
		s[i] = 'X';
	}
	cout<<"The result is: "<<s<<endl;
}
int main()
{
	whileloop();
	traditionalforloop();
	return 0;
}