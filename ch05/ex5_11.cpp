#include<iostream>
#include<string>
using namespace std;
int main()
{	
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt = 0, tCnt = 0, fCnt = 0;
	char ch;
	while(ch = getchar())
	{
		if(ch>=65 && ch<=90) //大写换小写
			ch += 32;
		switch(ch){
			case 'a':
			    ++aCnt;
				break;
			case 'e':
			    ++eCnt;
				break;
			case 'i':
			    ++iCnt;
				break;
			case 'o':
			    ++oCnt;
				break;
			case 'u':
			    ++uCnt;
				break;
			case 32:
			    ++sCnt;
				break;
			case '\t':
			    ++tCnt;
				break;
			case '\n':
			    ++fCnt;
				break;
		}
	}
	
	cout<<"Number of vowel a: \t"<<aCnt<<'\n'
	    <<"Number of vowel e: \t"<<eCnt<<'\n'
		<<"Number of vowel i: \t"<<iCnt<<'\n'
		<<"Number of vowel o: \t"<<oCnt<<'\n'
		<<"Number of vowel u: \t"<<uCnt<<'\n'
		<<"Number of space: \t"<<sCnt<<'\n'
		<<"Number of tab: \t"<<tCnt<<'\n'
		<<"Number of newline: \t"<<fCnt<<'\n';
	return 0;
}