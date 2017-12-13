#include<iostream>
#include<string>
using namespace std;
int main()
{
	string word1,word2;
	cin>>word1;
	while(cin>>word2)
	{
		if(word2==word1)
			break;
		word1=word2;
	}
	if(word2==word1)
		cout<<word1<<" appears twicely."<<endl;
	else
		cout<<"No word appears twicely."<<endl;
	return 0;
}