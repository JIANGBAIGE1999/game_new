#pragma once
#pragma execution_character_set("utf-8")

#include<vector>
#include"PartView.h"
#include"VecPosition.h"
#include"Debug.h"
class QuickAddPartViews				//�������PartView
{
public:
	QuickAddPartViews();
	~QuickAddPartViews();
	QuickAddPartViews* addPartView(std::vector<PartView*> partviewList);
protected:
	int setStartPosition(double x, double y);
	int add(int list[], int size);
	virtual void addList();
	std::vector<PartView*> partviewList;
	VecPosition startPosition;
	double lastWidth;								//PartView�Ŀ��
	int page;										//֧�ַ�ҳ��ͼ
};
