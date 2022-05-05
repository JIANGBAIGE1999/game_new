#include "Mci.h"


int Mci::num = 0;
Mci::Mci(LPCTSTR strResType, LPCTSTR strResName,bool isWav)
{
	char tmppath[200];
	::GetTempPath(200, tmppath);
	
	if (isWav)
		sprintf_s(fileName, "%s%d.wav", tmppath, num++);
	else
		sprintf_s(fileName, "%s%d.mp3", tmppath, num++);
	sprintf_s(mcicmd, 200,"open \"%s\" alias mymusic", fileName);
	SourceToTempFile(fileName, strResType, strResName);
}

Mci::~Mci()
{
	mciSendString(("close mymusic"), NULL, 0, NULL);
	// ɾ����ʱ�ļ�
	DeleteFile(fileName);
}

bool Mci::SourceToTempFile(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	// �����ļ�
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// ������Դ�ļ��С�������Դ���ڴ桢�õ���Դ��С
	HRSRC    hRes = ::FindResource(NULL, strResName, strResType);
	if (hRes == NULL) return false;
	HGLOBAL    hMem = ::LoadResource(NULL, hRes);
	DWORD    dwSize = ::SizeofResource(NULL, hRes);

	// д���ļ�
	DWORD dwWrite = 0;      // ����д���ֽ�
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	if (::CloseHandle(hFile) == false)
		return false;
	return true;
}

int Mci::play()
{
	DWORD e =mciSendString(mcicmd, NULL, 0, NULL);
	char a[100];
	mciGetErrorString(e, a, strlen(a));
	DWORD e1=mciSendString("play mymusic from 0", NULL, 0, NULL);
	char a1[100];
	mciGetErrorString(e1, a1, strlen(a));
	return 0;
}

int Mci::stop()
{
	mciSendString(("stop mymusic"), NULL, 0, NULL);
	return 0;
}
