#include<iostream>
#include<vector>
using namespace std;

//原程序
void index()
{
	//以10分为一个分数段统计成绩的数量：0~9, 10~19, ..., 90~99, 100
	vector<unsigned> scores(11,0); //11个分数段，全部初始化为0
	unsigned grade;
	while(cin >> grade){           //读取成绩
		if(grade <= 100)           //只处理有效的成绩
		    ++scores[grade/10];    //将对应分数段的计数值加1 
	}
	
	cout<<"Statistics are:"<<endl;
	for(int i = 0; i < 11; i ++)
	{
		if(i!=10)
		{
			cout<< i*10 <<"~"<<i*10+9<<": "<<scores[i]<<endl;
		}
		else
		{
			cout<< "100: "<<scores[i]<<endl;
		}
	}
}

//迭代器版本
void iteration()
{
	//以10分为一个分数段统计成绩的数量：0~9, 10~19, ..., 90~99, 100
	vector<unsigned> scores(11,0); //11个分数段，全部初始化为0
	unsigned grade;
	while(cin >> grade){           //读取成绩
		if(grade <= 100)           //只处理有效的成绩
		    ++(*(scores.begin()+grade/10));    //将对应分数段的计数值加1 
	}
	
	cout<<"Statistics are:"<<endl;
	for(auto b = scores.cbegin(); b!=scores.cend(); b++)
	{
		if(b!=scores.cend()-1)
		{
			cout<< (b-scores.cbegin())*10 <<"~"<<(b-scores.cbegin())*10+9<<": "<<*b<<endl;
		}
		else
		{
			cout<< "100: "<<*b<<endl;
		}
	}
}

int main()
{
	iteration();
	return 0;
}