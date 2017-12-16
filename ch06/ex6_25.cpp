#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		cout<<"Wrong parameter number."<<endl;
		return -1;
	}
	
	string s(strcat(argv[1],argv[2]));
	cout<<s<<endl;
	
	return 0;
}