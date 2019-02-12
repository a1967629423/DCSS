#pragma once
#include "base.h"
#define u8_count(x,y) ((x>>(8-y))&1)
class u8String
{
public:
	class u8const_iterator
	{
	public:
		const char* _Ptr;
		u8const_iterator(const char *sstr) :_Ptr(sstr){}
		u8const_iterator& operator ++()
		{
			int _cout = checkUTF8_string(*_Ptr);
			if (!_cout)_Ptr++;
			for (;_cout;_cout--)
			{
				_Ptr++;
			}
			return *this;
		}
		u8const_iterator& operator --()
		{
			if (!u8_count(1,*_Ptr))_Ptr--;
			while (u8_count(1,*_Ptr)&&!u8_count(2, *_Ptr))_Ptr--;
			return *this;
		}
		string operator *()
		{
			const char *n_ptr = _Ptr;
			vector<char> returnChar = vector<char>();
			int _cout = checkUTF8_string(*_Ptr);
			if (!_cout)returnChar.push_back(*n_ptr);
			for (; _cout; _cout--)
			{
				returnChar.push_back(*n_ptr);
				n_ptr++;
			}
			returnChar.push_back('\0');
			string _data = returnChar.data();
			return _data;
		}
		bool operator!=(const u8const_iterator& _u8itor)
		{
			return _u8itor._Ptr != _Ptr;
		}
		bool operator ==(const u8const_iterator& _u8itor)
		{
			return _u8itor._Ptr == _Ptr;
		}
		
		
	protected:
		int checkUTF8_string(char utf)
		{
			if (!u8_count(utf, 1))return 0;
			if (u8_count(utf, 3))return 3;
			if (u8_count(utf, 2))return 2;
			if (u8_count(utf, 1))return 1;
			return 0;
		}
	};
	u8String(string _sstr) :_str(_sstr) {}
	const u8const_iterator begin()
	{
		return u8const_iterator(_str.begin()._Ptr);
	}
	const u8const_iterator end()
	{
		return u8const_iterator(_str.end()._Ptr);
	}
protected:
	string _str;//utf-8
};

