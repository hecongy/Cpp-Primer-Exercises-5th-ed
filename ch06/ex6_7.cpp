#include<iostream>
using namespace std;
int get_value()
{
	static int val = 0;
	return val++;
}

int main()
{	
    cout<<"Press y to continue, n to stop."<<endl;
	char ch;
    while(cin>>ch)
	{
		if(ch=='y')
			cout<<get_value()<<endl;
		if(ch=='n')
			break;
	}		
}