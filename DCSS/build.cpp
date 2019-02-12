#include "build.h"
#include "Tools.h"
#include "u8String.h"
bool build::run()
{
	return step1() && step2() && step3();
}
string ErrorFormat(int _code, string Info, string attachInfo)
{
	return "ERROR: code: " + to_string(_code) + " info: " + Info + " " + attachInfo;
}
void build::SetErrorInfo(int _code, string attachInfo)
{
	switch (_code)
	{
	case 0:
		ErrorInfo = ErrorFormat(_code, "", attachInfo);
		break;
	default:
		ErrorInfo = ErrorFormat(_code, "未知错误", attachInfo);
		break;
	}
}
bool build::step1()
{
	//移除所有注释
	regex removeNoteRegex(string("(/\\*(\\s|\\S)*\\*/|//\\S*)"));
	regex removeAllSpace(string("[ \\f\\r\\t\\v]"));
	auto result1 = regex_replace(source, removeNoteRegex,string());
	Tools::regex_match_ex(result1, string("[^\\n]*"), [&](string str) {
		vector<wchar_t> vc = vector<wchar_t>();
		string utf8str = UTF8_To_string(str);		
		sourceFormat.push_back(vc);
		//添加行号与列号
		cout << to_string((int)sourceFormat.size()) + "." + str << endl;
	});
	return true;
}
string build::GetErrorInfo()
{
	return ErrorInfo;
}
bool build::step2()
{
	return true;
}
bool build::step3()
{
	return true;
}

build::~build()
{
}
