#pragma once
#pragma execution_character_set("utf-8")
#include<Windows.h>
#include"main.h"
#include"Application.h"
#include "StartActivity.h"
#include"GameActivity.h"
#include"Debug.h"


int srcWidth;			//��Ļ���
int srcHeight;			//��Ļ�߶�
int fps;				//��Ϸ�fps
double gameTime;			//��Ϸ������ʱ�䣨��ϵͳʱ�䣩
long long sumfps;		//��Ϸˢ����֡��
GameActivity *gameActivity;

Application::Application()
{
	debug.GameLog("Application Created!");
	fps = 60;
	gameTime = 0;
	timeForFps = 1.0 / (fps+1);
	srcHeight = 480;
	srcWidth = 640;
	sumfps = 0;
	
	initgraph(srcWidth,srcHeight);		//��ʼ������
	hwnd = GetHWnd();					//��ȡ���ھ��
	SetWindowTextW(hwnd,L"�궷��");
	onCreate();
	
}

Application::~Application()
{
	for (int i = 0; activityList.size(); i++)
		delete(activityList[i]);
	closegraph(); 
}

int Application::onCreate()
{
	
	activityList.push_back(startActivity);
	activityList.push_back(gameActivity);
	thisActivity = 0;
	setActivity(thisActivity);
	return 0;
}

int Application::getW()
{
	return srcWidth;
}

int Application::getH()
{
	return srcHeight;
}

int Application::testFps()
{
	static DWORD last;
	if(last==0)last= timeGetTime();
	static int times;		//����
	if (times++ >= 60)
	{
		nowFps = 1000.0/(timeGetTime() - last)*60;
		times = 0;
		//debug.GameLog(nowFps);
		last = timeGetTime();
	}
	return 0;
}


int Application::start()
{
	char s[20];
	debug.GameLog("Application start.");
	LARGE_INTEGER frequency,				//����֧�ֵĸ߾��ȼ�ʱ��Ƶ��
		last, cur;
	if (QueryPerformanceFrequency(&frequency) == false)
	{
		debug.GameError("��֧�ָ߾��ȼ�ʱ����");
		return 1;
	}
	while (isGameEnd==false)
	{
		QueryPerformanceCounter(&last);
		testFps();
		BeginBatchDraw();		//��ͼ����
		cleardevice();
		activityList[thisActivity]->ListenKey();
		activityList[thisActivity]->run();
		sprintf_s(s, "fps:%.2f", nowFps);
		outtextxy(0, 0, s);
		//FlushBatchDraw();
		EndBatchDraw();
		sumfps++;
		gameTime += timeForFps;
		isGameEnd = activityList[thisActivity]->isExit();
		if (activityList[thisActivity]->trunActivity() != thisActivity)
			setActivity(activityList[thisActivity]->trunActivity());
		for (QueryPerformanceCounter(&cur);
			(cur.QuadPart - last.QuadPart) / (double)(frequency.QuadPart) < timeForFps /*|| GetForegroundWindow() != hwnd*/
			;)
		{
			QueryPerformanceCounter(&cur);
		}
	}
	debug.GameLog("Applicationt�˳�start.");
	return 0;
	
}

int Application::exit()
{
	isGameEnd = true;
	debug.GameLog("Application Exit");
	return 0;
}

int Application::setActivity(unsigned int i)
{
	char s[40];
	sprintf_s(s, 40,"Application setApplication (%u)",i);
	debug.GameLog(s);
	
	
	if (activityList[thisActivity] != NULL)
	{
		delete activityList[thisActivity];
		activityList[thisActivity] = NULL;
		thisActivity = i;
		setActivity(i);
	}
	else
	{
		if (i == 0)
			activityList[thisActivity] = new StartActivity();
		else if (i == 1)
			activityList[thisActivity] =::gameActivity = new GameActivity();
		else
			debug.GameTip(i);
	}
	
	return 0;
}
