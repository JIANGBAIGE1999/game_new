#pragma once
#pragma execution_character_set("utf-8")
#include<vector>
#include"PartView.h"
#include"VecPosition.h"
#include"Debug.h"
class AddTree				//����������Ĺ�����
{
public:
	AddTree();
	~AddTree();
	AddTree* addPartView(std::vector<PartView*> partviewList);
private:
	int setStartPosition(double x, double y);
	int add(int list[], int size);
	void addList();
	std::vector<PartView*> partviewList;
	VecPosition startPosition;
	double lastWidth;								//PartView�Ŀ��
	int page;										//֧�ַ�ҳ��ͼ
};
