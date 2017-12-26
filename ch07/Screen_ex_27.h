#include<iostream>
#include<string>
using namespace std;

class Screen
{
	public:
	    typedef string::size_type pos;
		Screen()=default;
		Screen(pos h, pos w):height(h),width(w),contents(h*w, ' '){}
		Screen(pos h, pos w, char c):height(h),width(w),contents(h*w, c){}
		char get() const
		{
			return contents[cursor];
		}
		Screen &move(pos r, pos c)
		{
			cursor = r*width + c;
			return *this;
		}
		
		inline Screen &set(char c)
		{
			contents[cursor] = c;
			return *this;
		}
		inline Screen &set(pos r, pos c, char ch)
		{
			contents[r*width+c] = ch;
			return *this;
		}
		
		Screen &display(ostream &os)
		{
			do_display(os);
			return *this;
		}
		
		const Screen &display(ostream &os) const
		{
			do_display(os);
			return *this;
		}
		
		
	private:
	    pos height=0, width=0, cursor=0;
		string contents;
		void do_display(ostream &os) const
		{
			os<<contents;
		}
	
};