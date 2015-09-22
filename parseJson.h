#include "json/document.h"
#include <map>
#include <vector>

using namespace std;
using namespace rapidjson;

class CGameRes
{
public:
	static CGameRes* getInstance();//����һ����ȡ�����ĺ���
	static void destroy();

private:
	/*
	����fileName��data�����Ͳ���������Ϊ�˴ﵽ�ı��Ŀ��
	*/
	void parseFile(const char* fileName, Document*& data);

private:
	static CGameRes* mInstance;
	/*�����Լ�����һ��getString�������ɸ����Լ�Ҫ������json�ļ����趨������βΣ�һ���޸ĵ���int id���ɲ鿴���ӵ�json�ļ����жԱȣ�*/
	const char* getString(Document* data, int id, const char* key);

public:
	Document* mData;
};