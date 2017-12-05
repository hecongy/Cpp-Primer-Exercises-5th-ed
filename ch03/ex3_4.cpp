#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

//输出较大的字符串
void biggerone()
{
	cout<<"Please input two strings: "<<endl;
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    if(s1==s2)
    {
        cout<<"Two input strings are same."<<endl;
    }
    else if(s1>s2)
    {
        cout<<"The bigger input string is: "<<s1<<endl;
    }
    else
    {
        cout<<"The bigger input string is: "<<s2<<endl;
    }
}

//输出较长的字符串
void longerone()
{
	cout<<"Please input two strings: "<<endl;
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    if(s1.size()==s2.size())
    {
        cout<<"Two input strings' length are same."<<endl;
    }
    else if(s1.size()>s2.size())
    {
        cout<<"The longer input string is: "<<s1<<endl;
    }
    else
    {
        cout<<"The longer input string is: "<<s2<<endl;
    }
}
int main()
{
    biggerone();
	longerone();
    return 0;
}
