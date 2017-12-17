#define NDEBUG
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> vec, vector<int>::size_type index)
{	
	if(index == 0)
	{
		#ifndef NDEBUG
	        cout<<index<<": ";
	    #endif
		cout<<vec[0]<<endl;
	}		
	else
	{
		print(vec, index-1);
		#ifndef NDEBUG
	        cout<<index<<": ";
	    #endif
		cout<<vec[index]<<endl;
	}		
}

int main()
{
	vector<int> vec{1,2,3,4,5};
	print(vec,vec.size()-1);
}