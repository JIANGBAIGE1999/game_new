#pragma once
#pragma execution_character_set("utf-8")
#include "Area.h"

/***
	View�����пɻ��ƶ���ĸ���
***/
class View:virtual public Area
{
protected:
public:
	int onCreate();
	View();
	View(double x, double y, double width, double height);
	virtual int message(int type, int value);		//����֧��Activity��View����Ϣ����				
	virtual ~View();
	virtual View* draw();
	virtual bool isExit();
};