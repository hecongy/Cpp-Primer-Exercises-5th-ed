#include<iostream>
using namespace std;
int main()
{
	int i1, i2;
	cin>>i1>>i2;
	if(i2==0)
	{
		cout<<"Wrong input."<<endl;
		return 0;
	}		
	cout<<i1/i2<<endl;
	return 0;
}