#pragma once
#include "base.h"
class Tools
{
public:
	Tools();
	static void regex_match_ex(string source, string reg, vector<string> &reuslt);
	static void regex_match_ex(string source, string reg, void (&lamba)(string str));
	static void regex_match_ex(string source, string reg, function<void(string)> lmd);
	~Tools();
};

