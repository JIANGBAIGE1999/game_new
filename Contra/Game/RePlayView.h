#pragma once
#pragma execution_character_set("utf-8")
#include<vector>
#include<graphics.h>
#include"View.h"
#include"VecPosition.h"


/**
		ѭ����ʾ��VIEW������gif
		�����ò��Ŵ����Ͳ���
*/
class RePlayView :public View
{
protected:
	std::vector<IMAGE> imgs;		//��vector�洢��ÿһ֡��ͼƬ
	std::vector<int> imgFps;		//ÿһ֡ͼƬ��ʾ����fps
	std::vector<int> FpsSumTop;		//ǰn-1֡����fps		
	std::vector<int> FpsSumEnd;		//�Ӻ���ǰ��fps
	int fpsSum;						//img����fps
	bool isFirstDraw;				//�Ƿ��ǵ�һ��draw
	long long firstDrawFps;			//��һ�λ���Viewʱ��
	long long drawedFps;			//��view�ӿ�ʼ��ʾ�����ھ����˶���fps
	long long drawTimes;			//��ͼ�ܴ���
	UINT TransPerantColor;			//bmp�ļ���͸����ɫ
	int onCreate();					//��view����ʱִ��

	int getSum(int n);											//�õ�ǰn+1֡��fps�ܺ�
	int getSumForEnd(int n);									//�õ���n+1֡�����һ֡��fps�ܺ�
public:
	bool isLoop;					//�Ƿ�ѭ����ʾ
	bool isSequence;				//�Ƿ�˳�����
	bool isTransparent;				//�Ƿ���͸��ͼƬ
	RePlayView();												//Ĭ��λ�ã�0��0����Ĭ�ϴ�С100x100		
	RePlayView(double x, double y, double width, double height);//��ʼ������λ�����С
	RePlayView(double width, double height);
	RePlayView(double width, double height, UINT color);		//λ����͸����ɫ
	int init();													//����
	RePlayView* addIMAGE(IMAGE img, int imgFps);						//���IMAGE��ָ��֡��
	RePlayView* addIMAGE(IMAGE img);									//��Ĭ��fps���
	int getFpsSum();											//�õ�����img��fps�ܺ�
	int update();
	View* draw();												//����ʼ��ʱ��λ�ô�С��ͼ
	View* draw(VecPosition *position);							//����ʼ��ʱ��λ�ô�С��ͼ
	View* draw(double x, double y);								//��С���䣬ָ��λ�û�ͼ
	View* draw(double x, double y, double width, double height);
	View* draw(const VecPosition&p);
	int getImgSum();
	int setFps(unsigned int i, int fps);
	
};