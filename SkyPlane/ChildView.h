
// ChildView.h : CChildView 类的接口
//


#pragma once
#include "stdafx.h"
#include "SkyPlane.h"
#include "Background.h"
#include "Player.h"
#include "GameManager.h"
#include "Tool.h"
#include "Star.h"
#include "Cloud.h"
#include "Angela.h"
/*
#include "GameObject.h"
#include "Plane.h"
#include "EnemySimpleBomb.h"
#include "PlayerMainGun.h"
#include "EnemyRedPlane.h"
*/

// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();  
// 特性
public:
	//绘图相关
	CRect m_client;//记录客户区大小
	CDC m_cacheDC;   //缓冲DC  
	CBitmap m_cacheCBitmap;//缓冲位图

	GameManager manager_;
	Angela angela1_;
	Angela angela2_;
//	Cloud cloud_;

/*
	Background background_;
	EnemySimpleBomb enemyBomb_;
	EnemyRedPlane enemyRedPlane_;
*/
// 操作
public:
// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();
	
	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};