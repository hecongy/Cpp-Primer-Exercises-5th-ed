#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{	
    vector<string> maxWords;
	string curWord;	
	int maxNum=1,curNum=1;
	cout<<"Please input words:"<<endl;
	
	//获得第一个输入的单词
	cin>>curWord;
	maxWords.push_back(curWord);
	string inputWord;
	while(cin>>inputWord)
	{
		if(inputWord == curWord) //重复输入
		{
			curNum++;
		}
		else //不重复输入
		{
			if(curNum>maxNum) //当前最大
			{
				maxWords={curWord};
				maxNum=curNum;
			}
			else if(curNum==maxNum) //当前最大之一
			{
				maxWords.push_back(curWord);
			}	
			curNum = 1;
		}
		curWord = inputWord; //当前输入
	}
	
	if(maxNum<=1)
		cout<<"No word repeats.";
	else
	{
		cout<<"Words: ";
		for(auto e:maxWords)
		{
			cout<<e<<" ";
		}
		cout<<"repeat "<<maxNum<<" times."<<endl;
	}
	return 0;
}