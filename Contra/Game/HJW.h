#pragma once
#pragma execution_character_set("utf-8")
#include<graphics.h>
#pragma comment( lib, "MSIMG32.LIB")


//������ʾ͸��ͼƬ
void putbmp(double x, double y, double w, double h, IMAGE *img, UINT color = 0);//λ���볤�����һ��������͸��ͼƬ��͸��ɫ

//TODO:������з���ֵ��û�б�delete
IMAGE** cutIMAGE(			//�ǵ�delete
	IMAGE* pDstImg,		// ����ͼ��� IMAGE ����ָ��
	int h,					//��Ϊ������
	int l,					//��Ϊ������
	double width,			//ÿһС��ͼƬ��width
	double height			//ÿһС��ͼƬ��height
);

//����������ڴ��ļ��ж�ȡͼ��
void FileToImg(
	IMAGE* pDstImg,		// ����ͼ��� IMAGE ����ָ��
	LPCTSTR pImgFile,		// ͼƬ�ļ���
	double nWidth = 0,		// ͼƬ��������
	double nHeight = 0,		// ͼƬ������߶�
	bool bResize = false	// �Ƿ���� IMAGE �Ĵ�С����ӦͼƬ
);

void SourceToImg(
	IMAGE* pDstImg,		// ����ͼ��� IMAGE ����ָ��
	LPCTSTR pResType,		// ��Դ����
	LPCTSTR pResName,		// ��Դ����
	double width = 0,		// ͼƬ��������
	double height = 0,		// ͼƬ������߶�
	bool bResize = false	// �Ƿ���� IMAGE �Ĵ�С����ӦͼƬ

);

//�����ڵ�ǰ�豸�ϻ���ָ��ͼ��
void showImg(
	double dstX,              // ����λ�õ� x ����
	double dstY,              // ����λ�õ� y ����
	double dstWidth,          // ���ƵĿ��
	double dstHeight,         // ���Ƶĸ߶�
	IMAGE *pSrcImg,        // Ҫ���Ƶ� IMAGE ����ָ��
	double srcX,              // ���������� IMAGE �����е����Ͻ� x ����
	double srcY,              // ���������� IMAGE �����е����Ͻ� y ����
	DWORD dwRop = SRCCOPY  // ��Ԫ��դ�����루�����ע��
);

// �ӵ�ǰ��ͼ�豸��ȡͼ��
void getImg(
	IMAGE* pDstImg,   // ����ͼ��� IMAGE ����ָ��
	double srcX,         // Ҫ��ȡͼ���������Ͻ� x ����
	double srcY,         // Ҫ��ȡͼ����������Ͻ� y ����
	double srcWidth,     // Ҫ��ȡͼ������Ŀ��
	double srcHeight     // Ҫ��ȡͼ������ĸ߶�
);
