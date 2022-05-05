#pragma once
#pragma execution_character_set("utf-8")
#include<string>
#include"View.h"
#include "Stars.h"
#include"SimpleImageView.h"
#include"PartView.h"

//TODO:�������new�Ƿ�delete
class Background :public View
{
private:
	double sumFps;
	std::vector<PartView*> partViewList;
	
	
	double mapLength;
	int onCreate();
	void tree();
	void wave();
public :
	VecPosition *curPosition;
	static const int MOVE;
	Background();
	~Background();
	int move(int x);
	void addPartView(PartView*pv);
	int message(int type, int value);
	int bindCurX();
	double getMapLength();
	double getMapX();
	bool mapIsComeToEnd();
	View* draw();
	std::vector<VecPosition> grassVecList;
	std::vector<VecPosition> waterVecList;
};