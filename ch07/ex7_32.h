#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Window_mgr
{
	public:
	    using ScreenIndex = vector<Screen>::size_type;
		void clear(ScreenIndex);
	private:
	    vector<Screen> screens{Screen(24, 80, ' ')};
};

class Screen
{
	public:
	    friend void Window_mgr::clear(ScreenIndex);
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

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = Screens[i];
	s.contents = string(s.height * s.width, ' ');
}