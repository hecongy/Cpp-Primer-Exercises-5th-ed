/*
* Exercise 2.42: Write your own version of the Sales_data.h header
* and use it to rewrite the exercise from $2.6.2(p.76)
*/
struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	
};