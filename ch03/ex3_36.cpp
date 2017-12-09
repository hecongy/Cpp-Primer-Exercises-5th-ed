#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,11};
	vector<int> vec1 = {1,2,3,4,5,6,7,8,9,10};
	vector<int> vec2 = {1,2,3,4,5,6,7,8,9,11};
	
	//比较数组
	bool flag = true;
	for(int i = 0; i<10; i++)
	{
		if(arr1[i]!=arr2[2])
		{
			flag = false;			
		}
	}
	if(flag)
	{
		cout<<"The two arrays are same."<<endl;
	}
	else
	{
		cout<<"The two arrays are different."<<endl;
	}
	
	//比较vector
	if(vec1!=vec2)
	{
		cout<<"The two vectors are different."<<endl;
	}
	else
	{
		cout<<"The two vectors are same."<<endl;
	}
	return 0;
}