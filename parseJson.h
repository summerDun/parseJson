#include "json/document.h"
#include <map>
#include <vector>

using namespace std;
using namespace rapidjson;

class CGameRes
{
public:
	static CGameRes* getInstance();//构建一个获取单例的函数
	static void destroy();

private:
	/*
	解析fileName，data的类型采用引用是为了达到改变的目的
	*/
	void parseFile(const char* fileName, Document*& data);

private:
	static CGameRes* mInstance;
	/*这里自己定义一个getString函数，可根据自己要解析的json文件来设定具体的形参，一般修改的是int id。可查看例子的json文件进行对比，*/
	const char* getString(Document* data, int id, const char* key);

public:
	Document* mData;
};