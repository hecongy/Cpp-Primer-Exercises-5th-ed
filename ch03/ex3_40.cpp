#include<iostream>
#include<string>
using namespace std;
int main()
{
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	char ca[100];
	strcpy(ca,ca1);
	strcat(ca,ca2);
	const char* cp = ca;
	while(*cp)
	{
		cout<<*cp;
		++cp;
	}
	cout<<endl;
	return 0;
}