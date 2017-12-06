#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string word;
	vector<string> words;
	cout<<"Please input word sequence:"<<endl;
	while(cin>>word)
	{
		words.push_back(word);
	}
	
	for(auto &e:words)
	{
		for(auto &c:e)
		{
			c = toupper(c);
		}		
	}
	
	cout<<"The result is:"<<endl;
	
	for(auto e:words)
	{
		cout<<e<<endl;
	}
	
	return 0;
}