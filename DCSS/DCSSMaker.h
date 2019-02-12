#pragma once
#include "base.h"
#include <fstream>
using namespace std;

class DCSSMaker
{
public:
	struct Setting
	{
		string soucePath;
		string outputPath;
	};
	Setting globalSetting;
	DCSSMaker();
	DCSSMaker(Setting setting);
	bool make();

	
protected:
private:
};