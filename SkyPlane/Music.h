#pragma once
#pragma once
#include <afxwin.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include "Resource.h"

class Music
{
private:
	static TCHAR tmpwav[_MAX_PATH];
	static TCHAR mcicmd[300];
	static Music *itself;
public:
	Music();

	~Music();

	static bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName) {//�м���ú���
																							 // �����ļ�
		HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
		if (hFile == INVALID_HANDLE_VALUE)
			return false;

		// ������Դ�ļ��С�������Դ���ڴ桢�õ���Դ��С
		HRSRC    hRes = ::FindResource(NULL, strResName, strResType);
		HGLOBAL    hMem = ::LoadResource(NULL, hRes);
		DWORD    dwSize = ::SizeofResource(NULL, hRes);

		// д���ļ�
		DWORD dwWrite = 0;      // ����д���ֽ�
		::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
		::CloseHandle(hFile);

		return true;
	}
	//--------------------------------------------------------------
	static void Init(int WAV, const TCHAR* name) {//��ʼ������
												  // ������ʱ�ļ����ļ���

		::GetTempPath(_MAX_PATH, Music::tmpwav);
		_tcscat_s(Music::tmpwav, name);        // VC2008��VC2010 ���� _tcscat_s ����
											   // ��wav ��Դ��ȡΪ��ʱ�ļ�
											   //ExtractResource(tmpwav,_T("WAVE"), "background.mp3");
											   // ע�����wave��Դ�� ID Ϊ�� IDR_BACKGROUND����������
		ExtractResource(Music::tmpwav, _T("WAVE"), MAKEINTRESOURCE(WAV));
		// ������
		_stprintf_s(Music::mcicmd, _T("open \"%s\" alias mymusic"), Music::tmpwav);        // VC2008��VC2010 ���� _stprintf_s ����
	}

	static void Play(int WAV, const TCHAR *name) {//���ź���
		Init(WAV, name);
		mciSendString(_T("close mymusic"), NULL, 0, NULL);//�ȹ��ٿ���ע��˳�򣡣���
		mciSendString(Music::mcicmd, NULL, 0, NULL);
		mciSendString(_T("play mymusic"), NULL, 0, NULL);
		DeleteFile(tmpwav);
	}//------------------------------------------------------------


	 //��������
	void Play(CString ID)
	{
		int *temp = new int;
		if (ID == "Mission_Begin")
		{
			*temp = WAV_Mission_Begin;
		}
		else if (ID == "Player_Shot")
		{
			*temp = WAV_Player_Shot;
		}
		else if (ID == "Enemy_Shot")
		{
			*temp = WAV_Enemy_Single_Shot;
		}
		else if (ID == "Explosion_Small")
		{
			*temp = WAV_Explosion_Small;
		}
		else if (ID == "BGM") {
			*temp = WAV_BGM;
		}
		AfxBeginThread(Music::Play_Music, temp);
	}

	static UINT Play_Music(LPVOID lpParam)
	{
		CString File_Name;
		File_Name.Format(_T("%d,.wav"), *static_cast<int *>(lpParam));
		Play(*static_cast<int *>(lpParam), File_Name);
		delete static_cast<int *>(lpParam);
		return 0;
	}

};

//TCHAR Music::tmpwav[] = _T("");
//TCHAR Music::mcicmd[] = _T("");

