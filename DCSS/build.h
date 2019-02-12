#pragma once
#include "base.h"
#include "DCSSMaker.h"
class build
{
public:
	build(DCSSMaker::Setting globalSetting,string _source) :setting(globalSetting),source(_source) {};
	bool run();
	string GetErrorInfo();
	~build();
protected:
	string source;
	DCSSMaker::Setting setting;
	/**
	 * 去掉注释，添加行号列号
	 */
	bool step1();
	/**
	 * 完成静态变量的计算，动态变量标识，完成DCSS继承，标识每个选择器使用的接口以及其对应的函数名
	 * 最后将DCSS中的变量分离成静态CSS与动态Javascript，完成静态CSS的编译
	 */
	bool step2();
	/**
	 * 结合支持库编译Javascript，最后全部输出
	 */
	bool step3();
	void SetErrorInfo(int _code, string attachInfo);
	vector<vector<wchar_t>> sourceFormat;
	string ErrorInfo;
};

