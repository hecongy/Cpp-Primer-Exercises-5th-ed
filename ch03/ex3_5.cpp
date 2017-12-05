#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

//拼接字符串
void concatenate()
{
    cout<<"Please input strings: "<<endl;
    string s1, s2;
    getline(cin,s1);
    while(getline(cin,s2))
    {
	s1 += s2;
    }
    cout<<"The result is: "<<s1<<endl;
}

//用空格拼接字符串
void concatenatewithspace()
{
    cout<<"Please input strings: "<<endl;
    string s1, s2;
    getline(cin,s1);
    while(getline(cin,s2))
    {		
	s1 += s2;
	s1 += " ";
    }
    cout<<"The result is: "<<s1<<endl;
}
int main()
{
    concatenate();
    concatenatewithspace();
    return 0;
}
