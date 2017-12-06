#include<iostream>
#include<string>
using namespace std;
int main()
{
	cout<<"Please input a string:"<<endl;
	string s;
	string result;
	getline(cin,s);
	for(char c:s)
	{
		if(!ispunct(c))
			result+=c;
	}
	cout<<"The result is: "<<result<<endl;
	return 0;
}