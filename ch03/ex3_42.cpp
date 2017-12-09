#include<iostream>
#include<vector>
using namespace std;
int main()
{	
	vector<int> vec{1,2,3,4,5};
	int arr[10];
	for(decltype(vec.size()) i = 0; i<vec.size(); i++)
	{
		arr[i] = vec[i];
	}
	return 0;
}