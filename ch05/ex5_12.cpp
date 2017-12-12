#include<iostream>
#include<string>
using namespace std;
int main()
{	
	unsigned fCnt = 0, lCnt = 0, iCnt = 0;
	bool flag = true; //flag标识是否是序列中的第一个字母
	char ch;
	while(cin >> ch)
	{		
		if(ch!='f' && flag) //不以f开头的第一个字母跳过
			continue;
		if(ch=='f' && flag) //以f开头的第一个字母将flag置反并跳过
		{
			flag = false;
			continue;
		}		
		switch(ch){
			case 'f':
			    ++fCnt;
				break;
			case 'l':
			    ++lCnt;
				break;
			case 'i':
			    ++iCnt;
				break;
		}
		flag=true; //序列处理完毕，flag置位
	}
	
	cout<<"Number of ff: \t"<<fCnt<<'\n'
	    <<"Number of fl: \t"<<lCnt<<'\n'
		<<"Number of fi: \t"<<iCnt<<'\n';
	return 0;
}