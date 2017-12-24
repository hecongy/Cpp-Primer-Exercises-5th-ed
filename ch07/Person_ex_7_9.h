#include<iostream>
#include<string>
using namespace std;

struct Person{
	public:
	    string name;
		string address;

	    string get_name() const
		{
			return name;
		}
		string get_address() const
		{
			return address;
		}
};

istream &read(istream &in, Person &person)
{
	in>>person.name>>person.address;
	return in;
}

ostream &print(ostream &out, const Person &person)
{
	out<<person.name<<" "<<person.address;
	return out;
}