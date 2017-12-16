#include<iostream>
#include<string>
using namespace std;

int main(int argc, char * argv[])
{
	//for(auto b = begin(argv); b < end(argv); b++)
	//{
		//string s(*b);
		//cout<<s<<endl;
	//}
	
	char * ia[] = {"hello","hi"};
	
	for(auto b = begin(argv); b<end(argv);b++)
	{
		//cout<<*b<<endl;
	}
	
	return 0;
}