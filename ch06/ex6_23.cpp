#include<iostream>
using namespace std;

void print(const int a[], size_t begin, size_t end)
{
	for(auto i = begin; i<end; i++)
	{
		cout<<a[i]<<endl;
	}
}

int main()
{
	int i = 0, j[2] = {0, 1};
	print(&i, 0, 1);
	print(j, 0 ,2);
	return 0;
}