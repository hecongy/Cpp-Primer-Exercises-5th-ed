#include<vector>
using namespace std;
int main()
{
	int arr[10];
	for(int i=0; i<10; i++)
	{
		arr[i]=i;
	}
	
	//数组拷贝
	int arr2[10];
	for(int i=0; i<10; i++)
	{
		arr2[i]=arr[i];
	}
	
	
	vector<int> ivec(10);
	for(int i=0; i<10; i++)
	{
		ivec[i] = i;
	}
	//vector拷贝
	vector<int> ivec2 = ivec;
	
	return 0;
}