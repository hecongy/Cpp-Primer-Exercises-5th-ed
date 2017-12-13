#include<iostream>
using namespace std;
int main()
{
	int i1, i2;
	
	while(cin>>i1>>i2)
	{
		try
	    {
	        cout<<i1/i2<<endl;
	    }
	    catch(exception err)
	    {
            cout<<err.what()<<"\n Try again? Enter y or n"<<endl;
            char c;
			cin>>c;
			if(!cin || c=='n')
				break;
	    }
	}
	
	return 0;
}