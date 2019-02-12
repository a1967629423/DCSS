#include "Tools.h"



Tools::Tools()
{

}
void  Tools::regex_match_ex(string source, string reg, vector<string> &result)
{
	regex r(reg);
	smatch s;
	string::const_iterator sci = source.cbegin();
	while (regex_search(sci,source.cend(),s,r))
	{
		for (auto i = s.begin(); i != s.end(); i++)
		{
			if (i->str() == "")
			{
				if(sci!=source.cend())
				sci++;
			}
			else
			{
				result.push_back(i->str());
				sci = s[0].second;
			}

		}
		if (sci == source.cend())break;
	}
}
void Tools::regex_match_ex(string source, string reg, void(&lamba)(string str))
{
	regex r(reg);
	smatch s;
	string::const_iterator sci = source.cbegin();
	while (regex_search(sci, source.cend(), s, r))
	{
		for (auto i = s.begin(); i != s.end(); i++)
		{
			if (i->str() == "")
			{
				if (sci != source.cend())
					sci++;
			}
			else
			{
				lamba(i->str());
				sci = s[0].second;
			}

		}
		if (sci == source.cend())break;
	}
}
void Tools::regex_match_ex(string source, string reg, function<void(string)> lmd)
{
	regex r(reg);
	smatch s;
	string::const_iterator sci = source.cbegin();
	while (regex_search(sci, source.cend(), s, r))
	{
		for (auto i = s.begin(); i != s.end(); i++)
		{
			if (i->str() == "")
			{
				//进入这个分支说明当前字符不符合正则但是还存在子串，需要将迭代器向前推进
				if (sci != source.cend())
					sci++;
			}
			else
			{
				lmd(i->str());
				sci = s[0].second;
			}

		}
		//不知为何，哪怕迭代器移动至结束正则也不会结束，所有手动跳出
		if (sci == source.cend())break;
	}
}

Tools::~Tools()
{
}
