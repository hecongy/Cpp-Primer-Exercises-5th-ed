#include<iostream>
#include<string>
using namespace std;

//判断string对象中是否含有大写字母
bool contains_capital(const string &s)
{
	for(auto c:s)
	{
		if(isupper(c))
			return true;
	}
	return false;
}

//把string对象全都改成小写形式
void tolower(string &s)
{
	for(auto &c:s)
	{
		c = tolower(c);
	}
}

int main()
{
	cout<<"Please input a string:"<<endl;
	string s;
	getline(cin,s);
	cout<<"The input string "<<(contains_capital(s)?"contains":"doesn't contain")<<" capital letter."<<endl;
	tolower(s);
	cout<<"The lower case version of input string is: "<<s<<endl;
	return 0;
}