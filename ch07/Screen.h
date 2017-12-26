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
		
	private:
	    pos height=0, width=0, cursor=0;
		string contents;
	
};