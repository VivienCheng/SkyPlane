
// ChildView.h : CChildView ��Ľӿ�
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

// CChildView ����

class CChildView : public CWnd
{
// ����
public:
	CChildView();  
// ����
public:
	//��ͼ���
	CRect m_client;//��¼�ͻ�����С
	CDC m_cacheDC;   //����DC  
	CBitmap m_cacheCBitmap;//����λͼ

	GameManager manager_;
	Angela angela1_;
	Angela angela2_;
//	Cloud cloud_;

/*
	Background background_;
	EnemySimpleBomb enemyBomb_;
	EnemyRedPlane enemyRedPlane_;
*/
// ����
public:
// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();
	
	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};