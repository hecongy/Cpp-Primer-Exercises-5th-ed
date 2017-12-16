#include<iostream>
using namespace std;
int compare(int val, int const* p)
{
	if(val>*p)
		return val;
	else
		return *p;
}

int main()
{
	cout<<"Please input two integers:"<<endl;
	int val1, val2;
	cin>>val1>>val2;
	cout<<"The larger one is: "<<compare(val1,&val2)<<endl;
	return 0;
}