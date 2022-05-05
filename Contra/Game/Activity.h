#pragma once
#pragma execution_character_set("utf-8")
#include<vector>
#include"View.h"
#include"KeyListenner.h"


/***
	Activity�������Ϊһ��������һ������
***/
class Activity:virtual public KeyListenner
{
	
protected:
	std::vector<View*> viewList;			//View�б�
	virtual int onCreate();		//Activity����ʱ���ã����������View
	
public:
	Activity();
	int addView(View* v);
	virtual ~Activity();
	Activity* run();
	virtual bool isExit();
	virtual int trunActivity();
};

