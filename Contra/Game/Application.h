#pragma once
#pragma execution_character_set("utf-8")
#include "Activity.h"


/***
Application����������������棨Activity����
***/
class Application
{

public:
	int getW();
	int getH();
	Application();
	~Application();
	int start();
	int exit();
	int setActivity(unsigned int i);

protected:
	HWND hwnd;
	std::vector<Activity*> activityList;			//Activity�б�
	int thisActivity;						//��ǰActivity
	bool isGameEnd = false;					//������Ϸ����
	double timeForFps;					//ÿһ֡ʱ��(��Ϸʱ��)
	double nowFps;
	double timeDelay;					//ÿһ֡�ӳ�ʱ�䣨ϵͳʱ�䣩
	int testFps();
	int onCreate();

private:
	Activity *startActivity;
	Activity *gameActivity;
};

extern Application *application;