#pragma once
#pragma execution_character_set("utf-8")
#include"Nfc.h"
#include"PartView.h"
#include"Bullets.h"
enum Bill_act {
	STAND,
	WALK,
	INWATER
};

enum JumpAct {
	j_UP,
	j_DOWN
};
enum DirectionX {
	RIGHT,
	LEFT,
	X_NULL
};

enum DirectionY {
	UP,
	DOWN,
	Y_NULL
};

class Bill : public View, public Physical
{
public:
	static int TX;
	static int TY;
	static int M_SHOOT;
	static int M_JUMP;
	Bill();
	~Bill();
	View* draw();
	void physical();
	int message(int type, int value);
	bool isLand();
private:
	int onCreate();
	bool isTouchLand();				//�ж���Ӿ��ʱ����û�е���
	Bill_act act;					//���ڵĶ���
	DirectionX directionX;
	DirectionY directionY;
	JumpAct jumpAct;
	bool isShooting;				//�����Ƿ��ڰ����
	bool isJump;
	double lastShootTime;
	bool isMoving;					//�Ƿ����ƶ�
	bool isDive;					//�Ƿ���Ǳˮ
	RePlayView *standRight;			//�泯�ұ�վ�𣨲���ǹ��
	RePlayView*standLeft;			//�泯���վ��(����ǹ)
	RePlayView*standUpRight;		//�泯�Ҿ�ǹ������ǹ��
	RePlayView*standUpLeft;			//�泯���ǹ������ǹ��
	RePlayView*standShootRight;		//�泯�ұ�վ�𣨿�ǹ��
	RePlayView*standShootLeft;		//�泯���վ�𣨿�ǹ��
	RePlayView*walkRight;			//�泯�ұ��ܣ�����ǹ��
	RePlayView*walkLeft;			//�泯����ܣ�����ǹ��
	RePlayView*walkShootRight;			//�泯�ұ��ܣ���ǹ��
	RePlayView*walkShootLeft;			//�泯����ܣ���ǹ��
	RePlayView*walkShootRightUp;	//�泯�ұ��ܣ������Ϸ���ǹ��
	RePlayView*walkShootLeftUp;		//�泯����ܣ������Ϸ���ǹ��
	RePlayView*walkShootRightDown;	//�泯����ܣ������·���ǹ��
	RePlayView*walkShootLeftDown;	//�泯����ܣ������·���ǹ��
	RePlayView*getDownRight;		//ſ�£��ұߣ�
	RePlayView*getDownLeft;			//ſ�£���ߣ�
	RePlayView*shootUpRight;		//���Ͽ�ǹ���ұߣ�
	RePlayView*shootUpLeft;			//���Ͽ�ǹ����ߣ�
	RePlayView*jumpRight;			//������
	RePlayView*jumpLeft;			//������
	RePlayView*inWaterRight;		//��ˮ��ң�
	RePlayView*inWaterLeft;			//��ˮ���
	RePlayView*inWaterShootUp_right;//��ˮ�￪ǹ�����ϣ�
	RePlayView*inWaterShootUp_left;	//��ˮ�￪ǹ�����ϣ�	
	RePlayView*inWaterShootUpRight;	//��ˮ�￪ǹ�������ϣ�
	RePlayView*inWaterShootUpLeft;	//��ˮ�￪ǹ�������ϣ�
	RePlayView*inWaterShootRight;	//��ˮ��ң�����ǹ��
	RePlayView*inWaterShootLeft;	//��ˮ��ң�������ǹ��
	RePlayView*dive;				//Ǳˮ
	std::vector<VecPosition> grassVecList;		//���б�
	std::vector<VecPosition> waterVecList;		//ˮ�б�
	std::vector<Area*> grassArea;
	Area *myFootArea;
	Area *myArea;
	Bullets *billBullets;
};

