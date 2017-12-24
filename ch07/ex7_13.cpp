#include<iostream>
#include "Sales_data_ex_7_12.h"
using namespace std;
int main()
{	

	if(cin){	
		
		Sales_data total(cin);

		while(cin){
			
			Sales_data trans(cin);

			if(total.isbn() == trans.isbn())
				total = total.combine(trans);
			else{

				print(cout,total);
				total = trans;
			}
		}
		print(cout,total);
	}else{

		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}