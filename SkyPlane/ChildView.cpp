// ChildView.cpp : CChildView ���ʵ��
//

#include "stdafx.h"
#include "SkyPlane.h"
#include "ChildView.h"
#include "Background.h"
#include "Point.h"
#include "Cloud.h"
#include "Angela.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// CChildView

CChildView::CChildView():angela1_(Point(Game_Width/3,Game_Height/5 * 4),1),angela2_(Point(Game_Width / 3 * 2, Game_Height / 5 * 4), 2)
{}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_NCCREATE()
//	ON_WM_NCDESTROY()
ON_WM_TIMER()
ON_WM_KEYDOWN()
ON_WM_CREATE()
END_MESSAGE_MAP()



// CChildView ��Ϣ�������

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	manager_.InitGame();//1.

	return TRUE;
}


void CChildView::OnPaint() 
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	
	// TODO: �ڴ˴������Ϣ����������
	
	// ��ҪΪ������Ϣ������ CWnd::OnPaint()

	//��ȡ����DCָ��
	CDC *cDC = this->GetDC();
	//��ȡ���ڴ�С
	GetClientRect(&m_client);
	//��������DC
	m_cacheDC.CreateCompatibleDC(NULL);
	m_cacheCBitmap.CreateCompatibleBitmap(cDC, m_client.Width(), m_client.Height());
	m_cacheDC.SelectObject(&m_cacheCBitmap);
	//��ʼ���� ����Ҫ���Ƶ����ݶ�����m_cacheDC��

	//angela1_.Draw(&m_cacheDC);
	//angela2_.Draw(&m_cacheDC);
	manager_.Draw(&m_cacheDC);


	cDC->BitBlt(0, 0, m_client.Width(), m_client.Height(), &m_cacheDC, 0, 0, SRCCOPY);
	//���ƽ���
	//������� Ҫʹ������Ч
	ValidateRect(&m_client);
	//�ͷŻ���DC
	m_cacheDC.DeleteDC();
	//�ͷŶ���
	m_cacheCBitmap.DeleteObject();
	//�ͷŴ���DC
	ReleaseDC(cDC);
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1, 10, NULL);
	return 0;
}



void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	angela1_.PerformFly();
	angela2_.PerformFly();
	manager_.AI();
	Invalidate(FALSE);//ǿ��ˢ�´���
	//CWnd::OnTimer(nIDEvent);
}




