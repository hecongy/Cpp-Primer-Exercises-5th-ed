#include<iostream>
#include<string>
struct Sales_data {
	
	private:
		std::string bookNo;
		unsigned units_sold = 0;
		double price = 0.0;
		double revenue = 0.0;
	
	public:
		bool input(std::istream &in)
		{
			in >> bookNo >>units_sold >>price;
			if(!in) return false;
			revenue = units_sold * price;
			return true;
		}

		void add(Sales_data data)
		{
			units_sold += data.units_sold;
			revenue += data.revenue;
		}
		
		Sales_data& combine(const Sales_data &data)
		{
			units_sold += data.units_sold;
			revenue += data.revenue;
			return *this;
		}

		void output(std::ostream &out)
		{
			out << bookNo << " " << units_sold << " " << revenue << " " << price << std::endl;
		}

		void print(std::ostream &out)
		{
			out << "Revenue of " << bookNo << " is " << revenue << std::endl;
		}
		
		std::string isbn() const
		{
			return bookNo;
		}
};