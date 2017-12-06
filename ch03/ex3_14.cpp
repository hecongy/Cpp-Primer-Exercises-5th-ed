#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cout<<"Please input integers:"<<endl;
	vector<int> ivec;
	int i;
	while(cin>>i)
	{
		ivec.push_back(i);
	}
	cout<<"All integers you input are:"<<endl;
	for(auto m:ivec)
	{
		cout<<m<<endl;
	}
	return 0;
}