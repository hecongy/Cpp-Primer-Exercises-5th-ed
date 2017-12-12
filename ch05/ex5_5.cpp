#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{	
	int grade;
	cin >> grade;
	while(grade<0 || grade>100)
	{
		cout<<"Wrong input!"<<endl;
		cout<<"Please input again: ";
		cin>>grade;
	}
	const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	const vector<string> tails = {"-","-","-","","","","","","+","+"};
	string lettergrade;
	if(grade<60)
		lettergrade = scores[0];
	else
	{
		lettergrade = scores[(grade-50)/10];		
		if(grade!=100)
		{
			lettergrade+=tails[grade%10];
		}
	}
	
	cout<<"Grade is: "<<grade<<", "<<lettergrade<<endl;
	return 0;
}