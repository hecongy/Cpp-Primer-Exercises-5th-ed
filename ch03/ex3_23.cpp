#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec(10);
	for(int i=0; i<10; i++)
	{
		ivec[i] = i;
	}
	
	cout<<"The origin vector is:"<<endl;
	for(auto it = ivec.begin(); it!=ivec.end(); it++)
	{
		cout<<*it<<endl;
		*it *= *it;
	}
	
	cout<<"The changed vector is:"<<endl;
	for(auto it = ivec.begin(); it!=ivec.end(); it++)
	{
		cout<<*it<<endl;
	}
	return 0;
}