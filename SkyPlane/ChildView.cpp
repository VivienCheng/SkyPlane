// ChildView.cpp : CChildView 类的实现
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



// CChildView 消息处理程序

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
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	
	// 不要为绘制消息而调用 CWnd::OnPaint()

	//获取窗口DC指针
	CDC *cDC = this->GetDC();
	//获取窗口大小
	GetClientRect(&m_client);
	//创建缓冲DC
	m_cacheDC.CreateCompatibleDC(NULL);
	m_cacheCBitmap.CreateCompatibleBitmap(cDC, m_client.Width(), m_client.Height());
	m_cacheDC.SelectObject(&m_cacheCBitmap);
	//开始绘制 把需要绘制的内容都贴到m_cacheDC中

	//angela1_.Draw(&m_cacheDC);
	//angela2_.Draw(&m_cacheDC);
	manager_.Draw(&m_cacheDC);


	cDC->BitBlt(0, 0, m_client.Width(), m_client.Height(), &m_cacheDC, 0, 0, SRCCOPY);
	//绘制结束
	//绘制完后， 要使窗口有效
	ValidateRect(&m_client);
	//释放缓冲DC
	m_cacheDC.DeleteDC();
	//释放对象
	m_cacheCBitmap.DeleteObject();
	//释放窗口DC
	ReleaseDC(cDC);
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1, 10, NULL);
	return 0;
}



void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	angela1_.PerformFly();
	angela2_.PerformFly();
	manager_.AI();
	Invalidate(FALSE);//强制刷新窗口
	//CWnd::OnTimer(nIDEvent);
}




