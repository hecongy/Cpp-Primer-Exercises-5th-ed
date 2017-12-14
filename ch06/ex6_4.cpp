#include<iostream>
using namespace std;
void printfact()
{
	int val;
	cout<<"Please input a integer: ";
	cin>>val;
	int result = 1;
	while(val>1)
	{
		result *= val;
		val--;
	}
	cout<<val<<"! is "<<result<<endl;
}

int main()
{
	printfact();
}