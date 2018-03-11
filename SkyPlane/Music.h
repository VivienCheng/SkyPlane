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

	static bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName) {//中间调用函数
																							 // 创建文件
		HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
		if (hFile == INVALID_HANDLE_VALUE)
			return false;

		// 查找资源文件中、加载资源到内存、得到资源大小
		HRSRC    hRes = ::FindResource(NULL, strResName, strResType);
		HGLOBAL    hMem = ::LoadResource(NULL, hRes);
		DWORD    dwSize = ::SizeofResource(NULL, hRes);

		// 写入文件
		DWORD dwWrite = 0;      // 返回写入字节
		::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
		::CloseHandle(hFile);

		return true;
	}
	//--------------------------------------------------------------
	static void Init(int WAV, const TCHAR* name) {//初始化函数
												  // 产生临时文件的文件名

		::GetTempPath(_MAX_PATH, Music::tmpwav);
		_tcscat_s(Music::tmpwav, name);        // VC2008、VC2010 请用 _tcscat_s 函数
											   // 将wav 资源提取为临时文件
											   //ExtractResource(tmpwav,_T("WAVE"), "background.mp3");
											   // 注：如果wave资源的 ID 为宏 IDR_BACKGROUND，这样做：
		ExtractResource(Music::tmpwav, _T("WAVE"), MAKEINTRESOURCE(WAV));
		// 打开音乐
		_stprintf_s(Music::mcicmd, _T("open \"%s\" alias mymusic"), Music::tmpwav);        // VC2008、VC2010 请用 _stprintf_s 函数
	}

	static void Play(int WAV, const TCHAR *name) {//播放函数
		Init(WAV, name);
		mciSendString(_T("close mymusic"), NULL, 0, NULL);//先关再开，注意顺序！！！
		mciSendString(Music::mcicmd, NULL, 0, NULL);
		mciSendString(_T("play mymusic"), NULL, 0, NULL);
		DeleteFile(tmpwav);
	}//------------------------------------------------------------


	 //播放声音
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

