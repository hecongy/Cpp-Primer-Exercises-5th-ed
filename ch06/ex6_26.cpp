#include<iostream>
#include<string>
using namespace std;

int main(int argc, char * argv[])
{
	for(auto b = argv + 1; b < argv + argc; b++)
	{
		string s(*b);
		cout<<s<<endl;
	}
	
	return 0;
}