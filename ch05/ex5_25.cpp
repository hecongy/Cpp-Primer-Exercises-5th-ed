#include<iostream>
using namespace std;
int main()
{
	int i1, i2;
	
	while(cin>>i1>>i2)
	{
		try
	    {
			if(i2==0)
				throw runtime_error("Divider can't be 0.");
	        cout<<i1/i2<<endl;
	    }
	    catch(exception err)
	    {
            cout<<err.what()<<"\nTry again? Enter y or n"<<endl;
            char c;
			cin>>c;
			if(!cin || c=='n')
				break;
	    }
	}
	
	return 0;
}