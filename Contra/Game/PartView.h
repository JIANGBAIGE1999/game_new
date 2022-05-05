#pragma once
#pragma execution_character_set("utf-8")

#include<vector>
#include"RePlayView.h"
#include"VecPosition.h"
/*
�̳�partView��ʹ��PartView�Դ���PartViewָ��drawView����ͼƬ��drawView����delete
*/
class PartView:public View
{
public:
	
	PartView();
	PartView(double width,double height, LPCTSTR pImgFile);
	PartView(double width, double height, RePlayView*inView);
	PartView(double x, double y, double width, double height);
	unsigned int getViewcount()const;
	virtual View* draw();
	PartView* addPosition(const VecPosition &position);
	PartView* addPosition(double x, double y);
	PartView* addPosition(const int array[][2], int size);
	PartView* drawLine(double x, double y, int count = 1,int direction = 0);
	PartView* setVecList(const std::vector<VecPosition> & list);
	std::vector<VecPosition> getVecList();
	double getMapMax()const;												//��ȡView���������
	int bindCurPosition(const VecPosition *curPosition);					//���þ�ͷ�ڵ�ͼ��λ��
	~PartView();
	int setPage(int page);
	double page;									//���ڷ�ҳ����ͼ
protected:
	std::vector<VecPosition> vecList;
	const VecPosition *curPosition;
	bool isBinded;
	RePlayView*drawView;
	double mapLength;
	std::string folder;								//��ͼͼƬ�ļ���
	double width;
	double height;
   


	int setTransparent(bool isTransparent);							//��replayerView����Ϊ͸��
	bool isWillShow(const VecPosition &position, const VecPosition &size)const;
	void folderToPartView(LPCTSTR pImgFile,double viewSizeX,double viewSizeY,int fps=8											
	);
	
	int onCreate();
	
	VecPosition g2l(const VecPosition &g)const;								//��ͼ�����뾵ͷ�����ת��
};

