#include<iostream>
using namespace std;
void swap(int *val1, int *val2)
{
	int tmp = *val1;
	*val1=*val2;
	*val2=tmp;
}

int main()
{
	cout<<"Please input two integers:"<<endl;
	int val1,val2;
	cin>>val1>>val2;
	cout<<"The input is: "<<val1<<", "<<val2<<endl;
	swap(&val1,&val2);
	cout<<"The output is: "<<val1<<", "<<val2<<endl;
	return 0;
}