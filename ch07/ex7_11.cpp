#include<iostream>
#include "Sales_data_ex_7_11.h"
using namespace std;

int main()
{
	Sales_data s1;
	Sales_data s2("bookno1");
	Sales_data s3("bookno1", 2, 1.5);
	Sales_data s4(cin);
	
	print(cout,s1);
	cout<<endl;
	print(cout,s2);
	cout<<endl;
	print(cout,s3);
	cout<<endl;
	print(cout,s4);
	cout<<endl;
}