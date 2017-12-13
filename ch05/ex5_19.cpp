#include<iostream>
#include<string>
using namespace std;
int main()
{	
	do
	{
		string s1, s2;
		cout<<"Please input two strings:"<<endl;
		cin >> s1 >> s2;
		cout<<"The shorter string is: "<< (s1<s2?s1:s2) << endl;
	}
	while (cin);
	return 0;
}