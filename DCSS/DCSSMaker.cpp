#include "DCSSMaker.h"
#include "FileHelp.h"
#include "build.h"
DCSSMaker::DCSSMaker()
{
	Setting setting;
	setting.outputPath = "";
	setting.soucePath = "";
	new (this)DCSSMaker(setting);
}
DCSSMaker::DCSSMaker(Setting setting) :globalSetting(setting) {

}
bool DCSSMaker::make()
{
	FileHelper *fileh = new FileHelper(globalSetting.soucePath, FileHelper::Tyle::Read);
	string filestring = fileh->readAllFile();
	build *b = new build(globalSetting, filestring);
	b->run();
	//cout <<"output: "+ this->globalSetting.outputPath + " source:  " + globalSetting.soucePath+" content: "+filestring << endl;
	fileh->close();
	return true;
}