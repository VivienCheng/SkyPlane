
// SkyPlane.h : SkyPlane Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSkyPlaneApp:
// �йش����ʵ�֣������ SkyPlane.cpp
//

class CSkyPlaneApp : public CWinApp
{
public:
	CSkyPlaneApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSkyPlaneApp theApp;
