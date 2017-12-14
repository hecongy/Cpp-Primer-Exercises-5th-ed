#include<iostream>
using namespace std;
int fact(int val)
{
	int result = 1;
	while(val>1)
	{
		result *= val;
		val--;
	}
	return result;
}

int main()
{
	cout<<"Please input a integer: ";
	int val;
	cin>>val;
	cout<<val<<"! is "<<fact(val)<<endl;
}