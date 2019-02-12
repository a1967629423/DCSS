#pragma once
#include "base.h"
#include <fstream>
class FileHelper
{
public:
	enum Tyle {
		Read,Write,
	};
	FileHelper(string path, Tyle type);
	//bool operator >>( char& c);
	//bool operator <<( char& c);
	string readAllFile();
	void wirteAllFile(string str);
	void close();
	~FileHelper();
protected:
	Tyle type;
	fstream fs;
	bool inEnd = false;
private:
};