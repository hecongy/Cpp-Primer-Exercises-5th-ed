#include<iostream>
using namespace std;
void reset(int &p)
{
	p=0;
}

int main()
{
	cout<<"Please input an integer:"<<endl;
	int val;
	cin>>val;
	cout<<"The input is: "<<val<<endl;
	reset(val);
	cout<<"The output is: "<<val<<endl;
	return 0;
}