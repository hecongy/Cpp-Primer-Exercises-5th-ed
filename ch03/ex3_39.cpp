#include<iostream>
#include<string>
using namespace std;
int main()
{
	//比较两个string对象
	string s1 = "A string example";
	string s2 = "A different string";
	if(s1<s2)
		cout<<"s1 < s2"<<endl;
	else if(s1==s2)
		cout<<"s1 = s2"<<endl;
	else
		cout<<"s1 > s2"<<endl;
	
	//比较两个C风格字符串
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	if(strcmp(ca1,ca2)<0)
		cout<<"ca1 < ca2"<<endl;
	else if(strcmp(ca1,ca2)==0)
		cout<<"ca1 = ca2"<<endl;
	else
		cout<<"ca1 > ca2"<<endl;
	return 0;
}