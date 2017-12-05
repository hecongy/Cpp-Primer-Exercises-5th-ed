#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	//一次读入一整行
	string line;
	getline(cin,line);
	cout<<"The line is: "<<line<<endl;
	
	//一次读入一个词
	string word;
	int count = 0;
	while(cin>>word)
	{
		count++;
	}
	cout<<count<<" words are input."<<endl;
	return 0;
}