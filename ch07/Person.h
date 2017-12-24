#include<string>
using namespace std;

struct Person{
	private:
	    string name;
		string address;
	
	public:
	    string get_name() const
		{
			return name;
		}
		string get_address() const
		{
			return address;
		}
};