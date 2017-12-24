#include<iostream>
#include<string>
using namespace std;

struct Sales_data {
		
	    Sales_data() = default;
		Sales_data(const string &s):bookNo(s){}
		Sales_data(const string &s, unsigned u, double p):
		    bookNo(s), units_sold(u), price(p), revenue(u*p){}
		Sales_data(istream &in)
		{
			double price = 0.0;
	        in >> bookNo >>units_sold >>price;
	        revenue = units_sold * price;
		}
		
		string bookNo;
		unsigned units_sold = 0;
		double price = 0.0;
		double revenue = 0.0;
		
		Sales_data& combine(const Sales_data &data)
		{
			units_sold += data.units_sold;
			revenue += data.revenue;
			return *this;
		}
		
		string isbn() const
		{
			return bookNo;
		}
		
		double avg_price() const
		{
			if(units_sold)
				return revenue/units_sold;
			else
				return 0;
		}
};

Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
	Sales_data sum = item1;
	return sum.combine(item2);
}

istream &read(istream &in, Sales_data &item)
{
	double price = 0.0;
	in >> item.bookNo >>item.units_sold >>item.price;
	item.revenue = item.units_sold * item.price;
	return in;
}

ostream &print(ostream &out, Sales_data &item)
{
	out<<"ISBN: "<<item.isbn()<<" sold out "<<item.units_sold<<" pieces, revenue is: "<<item.revenue<<", average price is: "<<item.avg_price();
	return out;
}