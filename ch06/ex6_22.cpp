#include<iostream>
using namespace std;
void swap(int **pp1, int **pp2)
{
	int *tmp = *pp1;
	*pp1 = *pp2;
	*pp2 = tmp;
}

int main()
{
	cout<<"Please input two integers:"<<endl;
	int *p1, *p2, val1, val2;
	cin>>val1>>val2;
	p1=&val1;
	p2=&val2;
	swap(&p1,&p2);
	cout<<"The output is: "<<*p1<<", "<<*p2<<endl;
	return 0;
}