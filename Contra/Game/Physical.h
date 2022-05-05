#pragma once
#pragma execution_character_set("utf-8")
#include "VecPosition.h"
class Physical
{
protected:
	VecPosition Position;		//λ��
	VecPosition Velocity;		//�ٶ�
	VecPosition Acceleration;	//���ٶ�
public:
	Physical();
	void update();
	VecPosition getA()const;
	int setA(const VecPosition &a);
	VecPosition getV()const;
	int setV(const VecPosition &v);
};
