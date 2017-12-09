#include<iostream>
using namespace std;
int main()
{
	int ia[3][4]={
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	
	//版本1
	cout<<"Version I:"<<endl;
	for(int(&row)[4] : ia)
	{
		for(int &col : row)
		{
			cout<<col<<" ";
		}
		cout<<endl;
	}
	
	//版本2
	cout<<"Version II:"<<endl;
	for(size_t i = 0; i<3; i++)
	{
		for(size_t j = 0; j<4; j++)
		{
			cout<<ia[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//版本3
	cout<<"Version III:"<<endl;
	for(int(*p)[4] = ia; p!=ia+3; p++)
	{
		for(int *q = *p; q!=*p+4; q++)
		{
			cout<<*q<<" ";
		}
		cout<<endl;
	}
	return 0;
}