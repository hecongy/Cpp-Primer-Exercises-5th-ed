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
	
	lettergrade = grade<60?scores[0]:scores[(grade-50)/10];
	lettergrade += grade==100?"":tails[grade%10];
	
	cout<<"Grade is: "<<grade<<", "<<lettergrade<<endl;
	return 0;
}