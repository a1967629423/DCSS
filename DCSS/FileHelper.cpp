#include "FileHelp.h"
FileHelper::FileHelper(string path, Tyle type):fs(path,ios::in|ios::out|ios::binary|ios::app),type(type)
{
	if (!fs.is_open())
	{
		cout << "文件 " + path + " 打开失败"<<endl;
		system("pause");
		programEnd(0);
	}
}
string FileHelper::readAllFile()
{
	vector<char> file;

	char a;
	while (fs.read(&a,1))
	{
		file.push_back(a);
	}
	if (a!='\0')
	{
		file.push_back('\0');
	}
	DWORD size = WideCharToMultiByte(CP_UTF8,
		0,
		(LPCWCH)file.data(),
		-1,
		NULL,
		0,
		NULL,
		NULL);
	return string(file.data());
}
void FileHelper::wirteAllFile(string str)
{
	fs << str;
}
void FileHelper::close()
{
	fs.close();
}
FileHelper::~FileHelper()
{
	close();
}