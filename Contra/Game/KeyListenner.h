#pragma once
#pragma execution_character_set("utf-8")
#include <Windows.h>

//�������̺��������
class KeyListenner
{
	static const int sum = 7;
	
	

public:
	KeyListenner();

	~KeyListenner();

	virtual int ListenKey();

	bool isClicked(int in);




};

