#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	cout<<"Please input strings:"<<endl;
	vector<string> svec;
	string s;
	while(getline(cin,s))
	{
		svec.push_back(s);
	}
	cout<<"All strings you input are:"<<endl;
	for(auto m:svec)
	{
		cout<<m<<endl;
	}
	return 0;
}