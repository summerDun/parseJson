#include "parseJson.h"
//#include "Cocos2dUtil.h"

CGameRes* CGameRes::mInstance = nullptr;

CGameRes* CGameRes::getInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new CGameRes();
	}

	return mInstance;
}

void CGameRes::destroy()
{
	if (mInstance)
	{
		delete mInstance;
	}

	mInstance = nullptr;
}

void CGameRes::parseFile(const char* fileName, Document*& data)
{
	//第一步，需要获取fileName的data，so要定义一个局部变量
	unsigned char* pBytes = 0;
	ssize_t size = 0;
	//s
	pBytes = FileUtils::getInstance()->getFileData(fileName, "r", &size);
	//第二步，判断读取到的数据是否成功
	if (pBytes == 0 || strcmp((const char*)pBytes, "") == 0)
	{
		data = nullptr;
		return ;
	}
	//第三步,把data数据赋给string对象
	string str = string((const char*)pBytes, size);
	data = new Document();
	//通过string对象进行解析
	data->Parse<0>((const char*)str.c_str());
	if (data->HasParseError())
	{
		free(pBytes);
		return;
	}

	free(pBytes);
}

void CGameRes::getString(Document* data, int id, const char* key)
{
	char strID[36] = { 0 };
	sprintf(strID, "%d", id);
	//根据关键字获取的是json根下的子字典
	const rapidjson::Value& dic = DICTOOL->getSubDictionary_json(*data, strID);
	if (!dic.IsNull())
		return DICTOOL->getStringValue_json(dic, key);//根据关键字获得子字典下的值
	return nullptr;
}