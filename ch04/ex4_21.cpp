#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> vec{1,2,3,4,5,6,7,8,9,10};
	for(auto &e : vec)
	{
		e%2==1?e*=2:e=e;
	}
	return 0;
}