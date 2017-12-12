#include<iostream>
#include<string>
using namespace std;
int main()
{
	int count = 0;
	char c;	
	while(cin>>c)
	{
		if(c=='a')
			count++;
		if(c=='e')
			count++;
		if(c=='i')
			count++;
		if(c=='o')
			count++;
		if(c=='u')
			count++;
		if(c=='A')
			count++;
		if(c=='E')
			count++;
		if(c=='I')
			count++;
		if(c=='O')
			count++;
		if(c=='U')
			count++;
	}
	
	cout<<"The number of vowels is: "<<count<<endl;
	return 0;
}