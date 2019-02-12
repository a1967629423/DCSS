#include "base.h"
#include "DCSSMaker.h"
using namespace std;
void programEnd(int _code)
{
	exit(_code);
}
string string_To_UTF8(const std::string & str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}
string UTF8_To_string(const std::string & str)
{
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
	memset(pwBuf, 0, nwLen * 2 + 2);

	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	memset(pBuf, 0, nLen + 1);

	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr = pBuf;

	delete[]pBuf;
	delete[]pwBuf;

	pBuf = NULL;
	pwBuf = NULL;

	return retStr;
}
int wmain(int argc, char *wargv[])
{
	system("chcp 65001");
	// Convert argv to to UTF8
	char** argv = new char*[argc];
	for (int i = 0; i < argc; i++) {
		// Compute the size of the required buffer
		DWORD size = WideCharToMultiByte(CP_UTF8,
			0,
			(LPCWCH)wargv[i],
			-1,
			NULL,
			0,
			NULL,
			NULL);
		if (size == 0) {
			// This should never happen.
			fprintf(stderr, "Could not convert arguments to utf8.");
			exit(1);
		}
		// Do the actual conversion
		argv[i] = new char[size];
		DWORD result = WideCharToMultiByte(CP_UTF8,
			0,
			(LPCWCH)wargv[i],
			-1,
			argv[i],
			size,
			NULL,
			NULL);
		if (result == 0) {
			// This should never happen.
			fprintf(stderr, "Could not convert arguments to utf8.");
			exit(1);
		}
	}
	DCSSMaker *maker = new DCSSMaker();
	switch (argc)
	{
	case 2:
		maker->globalSetting.soucePath = argv[1];
		maker->globalSetting.outputPath = "./{filename}";
		break;
	case 3:
		maker->globalSetting.soucePath = argv[1];
		maker->globalSetting.outputPath = argv[2];
		break;
	default:
		break;
	}
	try
	{
		maker->make();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	
	system("pause");
	return 1;
}