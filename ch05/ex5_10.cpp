#include<iostream>
#include<string>
using namespace std;
int main()
{	
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while(cin >> ch)
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
		}
	}
	
	cout<<"Number of vowel a: \t"<<aCnt<<'\n'
	    <<"Number of vowel e: \t"<<eCnt<<'\n'
		<<"Number of vowel i: \t"<<iCnt<<'\n'
		<<"Number of vowel o: \t"<<oCnt<<'\n'
		<<"Number of vowel u: \t"<<uCnt<<'\n';
	return 0;
}