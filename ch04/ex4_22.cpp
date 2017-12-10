#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int grade;
	cin>>grade;
	
	//版本1
	cout<<((grade>90)?"high pass":(grade>75)?"pass":(grade>=60)?"low pass":"fail")<<endl;
	
	//版本2
	if(grade>90)
	{
		cout<<"high pass"<<endl;
	}
	if(grade<=90 && grade >75)
	{
		cout<<"pass"<<endl;
	}
	if(grade<=75 && grade >=60)
	{
		cout<<"low pass"<<endl;
	}
	if(grade<60)
	{
		cout<<"fail"<<endl;
	}
	return 0;
}