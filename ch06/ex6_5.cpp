#include<iostream>
using namespace std;
void absolute(int val)
{
	int result = val;
	if(val<0)
		result = -val;
	cout<<"Absolute value of "<<val<<" is "<<result<<endl;
}

int main()
{	
	cout<<"Please input a integer: ";
	int val;
	cin>>val;
	absolute(val);
}