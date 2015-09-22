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
	//��һ������Ҫ��ȡfileName��data��soҪ����һ���ֲ�����
	unsigned char* pBytes = 0;
	ssize_t size = 0;
	//s
	pBytes = FileUtils::getInstance()->getFileData(fileName, "r", &size);
	//�ڶ������ж϶�ȡ���������Ƿ�ɹ�
	if (pBytes == 0 || strcmp((const char*)pBytes, "") == 0)
	{
		data = nullptr;
		return ;
	}
	//������,��data���ݸ���string����
	string str = string((const char*)pBytes, size);
	data = new Document();
	//ͨ��string������н���
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
	//���ݹؼ��ֻ�ȡ����json���µ����ֵ�
	const rapidjson::Value& dic = DICTOOL->getSubDictionary_json(*data, strID);
	if (!dic.IsNull())
		return DICTOOL->getStringValue_json(dic, key);//���ݹؼ��ֻ�����ֵ��µ�ֵ
	return nullptr;
}